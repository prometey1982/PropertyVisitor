#include "GoldProperty.h"
#include "PropertyFactory.h"

namespace PropertyVisitor
{
	namespace
	{
		PropertyFactoryRegistrator<GoldProperty> registrator;
	}

	const char GoldProperty::propertyName[] = "gold";
}
