#pragma once

#include <memory>
#include <unordered_map>

namespace PropertyVisitor
{

	class Property;

	class PropertyFactory
	{
	public:
		typedef std::unique_ptr<Property> (*createFunctionT)();

		static void registerFactory(const char propertyName[], createFunctionT createFunction);
		static std::unique_ptr<Property> createProperty(const char propertyName[]);

	private:
		PropertyFactory();

		static PropertyFactory & instance();

	private:
		std::unordered_map<std::string, createFunctionT> factoryMap;
	};

	template<typename PropertyType>
	class PropertyFactoryRegistrator
	{
	public:
		static std::unique_ptr<Property> createProperty()
		{
			return std::make_unique<PropertyType>();
		}

		PropertyFactoryRegistrator()
		{
			PropertyFactory::registerFactory(PropertyType::propertyName, &createProperty);
		}
	};

} // namespace PropertyVisitor
