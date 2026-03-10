#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"


int main()
{
	Data *zadata = new Data(5);
	Data *zaothadata = new Data();
	Data *zasuperiadata = new Data(*zaothadata);

	uintptr_t uintone;
	uintptr_t uinttwo;
	uintptr_t uinttree;

	std::cout << "zadata: " << zadata << " : " << zadata->getNumber() << std::endl;
	std::cout << "zaothadata: " << zaothadata << " : " << zaothadata->getNumber() << std::endl;
	std::cout << "zasuperiadata: " << zasuperiadata << " : " << zasuperiadata->getNumber() << std::endl;

	std::cout << "********* Serializer call, serialize *********" << std::endl;

	uintone = Serializer::serialize(zadata);
	std::cout << "zadata serialized into uintone: " << zadata << " : " << uintone << std::endl;

	uinttwo = Serializer::serialize(zaothadata);
	std::cout << "zaothadata serialized into uinttwo: " << zaothadata << " : " << uinttwo << std::endl;

	uinttree = Serializer::serialize(zasuperiadata);
	std::cout << "zasuperiadata serialized into uinttree: " << zasuperiadata << " : " << uinttree << std::endl;

	std::cout << "******** Serializer call, deserialize ********" << std::endl;

	zadata = Serializer::deserialize(uinttwo);
	std::cout << "uinttwo deserialized into zadata: " << uinttwo << " : " << zadata << std::endl;

	zaothadata = Serializer::deserialize(uinttree);
	std::cout << "uinttree deserialized into zaothadata: " << uinttree << " : " <<  zaothadata << std::endl;

	zasuperiadata = Serializer::deserialize(uintone);
	std::cout << "uintone deserialized into zasuperiadata: " << uintone << " : " << zasuperiadata << std::endl;

	std::cout << "******************* Result *******************" << std::endl;

	std::cout << "zadata: " << zadata << " : " << zadata->getNumber() << std::endl;
	std::cout << "zaothadata: " << zaothadata << " : " << zaothadata->getNumber() << std::endl;
	std::cout << "zasuperiadata: " << zasuperiadata << " : " << zasuperiadata->getNumber() << std::endl;

	delete (zadata);
	delete (zaothadata);
	delete (zasuperiadata);

	return (0);
}