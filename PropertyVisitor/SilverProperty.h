#pragma once

#include "PropertyBase.h"

namespace PropertyVisitor
{

	class SilverProperty : public PropertyBase<SilverProperty>
	{
	public:
		static const char propertyName[];

		SilverProperty(unsigned silver = 0)
			: silver_(silver)
		{
		}

		unsigned getSilver()
		{
			return silver_;
		}

	private:
		unsigned silver_;
	};

}
