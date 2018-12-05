#pragma once

#include "PropertyBase.h"

namespace PropertyVisitor
{

	class GoldProperty : public PropertyBase<GoldProperty>
	{
	public:
		static const char propertyName[];

		GoldProperty(unsigned gold = 0)
			: gold_(gold)
		{
		}

		unsigned getGold()
		{
			return gold_;
		}

	private:
		unsigned gold_;
	};

}
