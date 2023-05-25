#include "CharnelHouse/Characters/PlayerCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "CharnelHouse/Data/InputActions.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	bUseControllerRotationYaw = false;
	if(InputActions->BaseMappingContext)
	{
		AddMappingContext(InputActions->BaseMappingContext,0);
	}else{Error("BaseMappingContext Is null");}
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CameraComponent->SetWorldRotation((GetActorLocation()-CameraComponent->GetComponentLocation()).Rotation());
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	if(UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		InputActions->IA_Move?EnhancedInputComponent->BindAction(InputActions->IA_Move,ETriggerEvent::Triggered,this,&APlayerCharacter::OnMove):Error("No MoveInputAction");
		InputActions->IA_Sprint?EnhancedInputComponent->BindAction(InputActions->IA_Sprint,ETriggerEvent::Triggered,this,&APlayerCharacter::OnSprintStart):Error("No SprintInputAction");
		InputActions->IA_Sprint?EnhancedInputComponent->BindAction(InputActions->IA_Sprint,ETriggerEvent::Completed,this,&APlayerCharacter::OnSprintEnd):Error("No SprintInputAction");
		InputActions->IA_Camera?EnhancedInputComponent->BindAction(InputActions->IA_Camera,ETriggerEvent::Triggered,this,&APlayerCharacter::UpdateCameraRotation):Error("No CameraInputAction");
		InputActions->IA_Jump?EnhancedInputComponent->BindAction(InputActions->IA_Jump,ETriggerEvent::Triggered,this,&APlayerCharacter::OnJump):Error("No IA_Jump");
	}
}

// Adds Mapping Context To Enhanced Input System
void APlayerCharacter::AddMappingContext(const UInputMappingContext* Context,int Priority) const
{
	if(const APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(Context,Priority);
		}
	}
}

// Prints Error Message on the Screen
void APlayerCharacter::Error(FString Message)
{
	GEngine->AddOnScreenDebugMessage(-1,50,FColor::Red,Message+" in "+ this->GetName());
}

// Player Movement Function
void APlayerCharacter::OnMove(const FInputActionValue& Value)
{
	FVector2D AxisValues = Value.Get<FVector2D>();
	FRotator CameraRotation = CameraComponent->GetComponentRotation();
	CameraRotation = FRotator(0,CameraRotation.Yaw,0);
	AddMovementInput(CameraRotation.Vector(),AxisValues.Y);
	AddMovementInput(UKismetMathLibrary::GetRightVector(CameraRotation),AxisValues.X);
}

// Function For when the player starts sprinting
void APlayerCharacter::OnSprintStart(const FInputActionValue& Value)
{
	if(PlayerProperties)
	{
		GetCharacterMovement()->MaxWalkSpeed = PlayerProperties->SprintSpeed;
	}else{Error("PlayerProperties is Null");}
}

// Function For When The Player Stops Sprinting
void APlayerCharacter::OnSprintEnd(const FInputActionValue& Value)
{
	if(PlayerProperties)
	{
		GetCharacterMovement()->MaxWalkSpeed = PlayerProperties->WalksSpeed;
	}else{Error("PlayerProperties is Null");}
}

// Function for updating the camera rotation
void APlayerCharacter::UpdateCameraRotation(const FInputActionValue& Value)
{
	FVector2D Axis = Value.Get<FVector2D>();
	float DeltaTime = GetWorld()->DeltaTimeSeconds;
	if(SpringArmComponent->GetRelativeRotation().Pitch + (Axis.Y * PlayerProperties->MouseYSensitivity*DeltaTime)<60 && SpringArmComponent->GetRelativeRotation().Pitch + (Axis.Y * PlayerProperties->MouseYSensitivity*DeltaTime)>-60 )
	{
		SpringArmComponent->AddRelativeRotation(FRotator(Axis.Y * PlayerProperties->MouseYSensitivity,Axis.X * PlayerProperties->MouseXSensitivity,0)*GetWorld()->DeltaTimeSeconds);	
	}
	else
	{
		SpringArmComponent->AddRelativeRotation(FRotator(0,Axis.X * PlayerProperties->MouseXSensitivity,0)*GetWorld()->DeltaTimeSeconds);	
	}
}

// Function For Player Jump
void APlayerCharacter::OnJump(const FInputActionValue& Value)
{
	GetCharacterMovement()->JumpZVelocity = PlayerProperties?PlayerProperties->JumpHeight:500;
	GetCharacterMovement()->bNotifyApex = true;
	Jump();
}

// Called When Player Reaches apex of jump
void APlayerCharacter::NotifyJumpApex()
{
	Super::NotifyJumpApex();
	GetCharacterMovement()->GravityScale = 2;
}

// Called When Player lands on a surface;
void APlayerCharacter::Landed(const FHitResult& Hit)
{
	Super::Landed(Hit);
	GetCharacterMovement()->GravityScale = 1;
}
