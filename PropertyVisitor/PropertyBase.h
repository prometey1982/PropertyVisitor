#pragma once

#include "PropertyVisitorBase.h"

namespace PropertyVisitor
{
	class Property
	{
	public:
		virtual ~Property();

		void accept(PropertyVisitorBase & visitor)
		{
			do_accept(visitor);
		}

	protected:
		Property()
		{
		}

		virtual void do_accept(PropertyVisitorBase & visitor) = 0;
	};

	template<typename ConcreteProperty>
	class PropertyBase : public Property
	{
	protected:
		PropertyBase()
		{
		}

		virtual void do_accept(PropertyVisitorBase & visitor)
		{
			visitor.visit(static_cast<ConcreteProperty &>(*this));
		}
	};

} // namespace PropertyVisitor
