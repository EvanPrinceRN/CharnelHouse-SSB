#include "CharnelHouse/Characters/PlayerCharacter.h"
#include "InputActionValue.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MotionWarpingComponent.h"
#include "CharnelHouse/Components/HealthMeter.h"
#include "CharnelHouse/Data/PlayerDataAsset.h"
#include "CharnelHouse/Libraries/MathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComponent            = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	MotionWarpingComponent        = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarp"));
	CameraComponent               = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArmComponent->SetupAttachment(GetRootComponent());
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw                         = false;
}

// Called every frame
void APlayerCharacter::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);
}

// Handles Player Movement Code.
void APlayerCharacter::Move( const FInputActionValue& Axis )
{
	FVector2D InputAxis = Axis.Get<FVector2D>();
	FRotator Rotation   = CameraComponent->GetComponentRotation();
	Rotation            = FRotator(0.f, Rotation.Yaw, 0.f);
	DodgeDirection      = Rotation.RotateVector(FVector(InputAxis.Y, InputAxis.X, 0));
	AddMovementInput(UMathLibrary::GetForwardVector(Rotation), InputAxis.Y);
	AddMovementInput(UMathLibrary::GetRightVector(Rotation), InputAxis.X);
}

// Handles Camera Control Code.
void APlayerCharacter::CameraControl( const FInputActionValue& Axis )
{
	FVector2D InputAxis = Axis.Get<FVector2D>();
	float XVal          = InputAxis.X;
	AddControllerYawInput(InputAxis.Y * 45.f);
	AddControllerPitchInput(XVal * 30.f);
}

// Handles Sprinting Code.
void APlayerCharacter::BeginSprint( const FInputActionValue& BoolValue )
{
	if ( BoolValue.Get<bool>() )
	{
		SetSprinting(true);
	}
	else
	{
		FTimerHandle SprintDelay;
		GetWorldTimerManager().SetTimer(SprintDelay, [&]()
		{
			SetSprinting(false);
		}, 0.02f, false);
	}
}

// Handles Dodging Code.
void APlayerCharacter::Dodge( const FInputActionValue& BoolValue )
{
	if ( !GetSprinting() && !GetDodging() )
	{
		SetDodging(true);
		SetActorRotation(DodgeDirection.Rotation());		
		FVector Direction = GetActorLocation();
		Direction += DodgeDirection * PlayerProperties->DodgeDistance;
		MotionWarpingComponent->AddOrUpdateWarpTargetFromLocation("Location", Direction);
		PlayAnimMontage(DodgeMontage);
		FTimerHandle DodgeDelay;
		GetWorldTimerManager().SetTimer(DodgeDelay, [&]()
		{
			SetDodging(false);
		}, 0.8f, false);
	}
}

// Sets the Health Values of the Player.
void APlayerCharacter::InitializeHealth()
{
	if ( Health && PlayerProperties )
	{
		Health->SetMaxHealth(PlayerProperties->MaxHealth);
		Health->SetCurrentHealth(Health->GetMaxHealth());
	}
}
