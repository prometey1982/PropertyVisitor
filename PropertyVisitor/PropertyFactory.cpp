#include "PropertyFactory.h"
#include "PropertyBase.h"

namespace PropertyVisitor
{
	/*static*/ void PropertyFactory::registerFactory(const char propertyName[], createFunctionT createFunction)
	{
		instance().factoryMap[propertyName] = createFunction;
	}

	/*static*/ std::unique_ptr<Property> PropertyFactory::createProperty(const char propertyName[])
	{
		PropertyFactory & that = instance();
		auto createMethod = that.factoryMap.find(propertyName);
		if (createMethod != that.factoryMap.end())
			return createMethod->second();

		return 0;
	}

	PropertyFactory::PropertyFactory()
	{
	}

	PropertyFactory & PropertyFactory::instance()
	{
		static PropertyFactory factory;
		return factory;
	}

} // namespace PropertyVisitor
