#include "PropertyObject.h"

namespace PropertyVisitor
{
	void PropertyObject::addProperty(std::unique_ptr<Property> prop)
	{
		properties_.emplace_back(std::move(prop));
	}

	void PropertyObject::accept(PropertyVisitorBase & visitor)
	{
		for (auto & prop : properties_)
			prop->accept(visitor);
	}

}
