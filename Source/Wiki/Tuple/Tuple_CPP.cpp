#include "Tuple_CPP.h"

ATuple_CPP::ATuple_CPP()
{

}

void ATuple_CPP::BeginPlay()
{
	Super::BeginPlay();	

	TTuple<float, int> Data = GetTuple();
	UE_LOG(LogTemp, Warning, TEXT("float: %f, int: %d"), Data.Get<0>(), Data.Get<1>())
}

TTuple<float, int> ATuple_CPP::GetTuple()
{
	return MakeTuple(.15f, 654);
}


