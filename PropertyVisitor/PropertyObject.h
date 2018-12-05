#pragma once

#include <vector>
#include <memory>
#include "PropertyBase.h"

namespace PropertyVisitor
{

	class PropertyObject
	{
	public:
		void addProperty(std::unique_ptr<Property> prop);

		void accept(PropertyVisitorBase & visitor);
	private:
		std::vector<std::unique_ptr<Property> > properties_;
	};

} // namespace PropertyVisitor
