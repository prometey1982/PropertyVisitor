#pragma once

#include "PropertyVisitorBase.h"

#include <functional>

namespace PropertyVisitor
{

	template<typename Property>
	class TemplatedPropertyVisitor : public PropertyVisitorBase
	{
	public:
		TemplatedPropertyVisitor(std::function<void(Property &)> func)
			: func_(func)
		{
		}

	private:
		virtual void visit(Property & prop)
		{
			func_(prop);
		}

		std::function<void(Property &)> func_;
	};

} // namespace PropertyVisitor
