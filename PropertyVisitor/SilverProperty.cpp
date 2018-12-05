#include "SilverProperty.h"
#include "PropertyFactory.h"

namespace PropertyVisitor
{
	namespace
	{
		PropertyFactoryRegistrator<SilverProperty> registrator;
	}

	const char SilverProperty::propertyName[] = "silver";
}
