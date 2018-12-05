#include "GoldProperty.h"
#include "SilverProperty.h"
#include "PropertyFactory.h"
#include "TemplatedPropertyVisitor.h"
#include "SubscribePropertyVisitor.h"
#include "PropertyObject.h"

#include <iostream>

using namespace PropertyVisitor;

int main(int argc, char * argv[])
{
	GoldProperty gold(10);
	auto gold1 = PropertyFactory::createProperty("gold");

	TemplatedPropertyVisitor<GoldProperty> templatedVisitor([](auto & gold)
	{
		std::cout << gold.getGold() << std::endl;
	});
	gold.accept(templatedVisitor);

	PropertyObject obj;
	obj.addProperty(std::make_unique<GoldProperty>(11));
	obj.addProperty(std::make_unique<SilverProperty>(12));
#if 1
	SubscribePropertyVisitor subscrVisitor;

	subscrVisitor.on<GoldProperty>([](auto & prop)
	{
		std::cout << "subscribe visitor, gold = " << prop.getGold() << std::endl;
	}).on<SilverProperty>([](auto & prop)
	{
		std::cout << "subscribe visitor, silver = " << prop.getSilver() << std::endl;
	});
#endif
	obj.accept(subscrVisitor);

	return 0;
}
