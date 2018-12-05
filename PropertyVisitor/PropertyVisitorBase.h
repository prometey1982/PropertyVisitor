#pragma once

namespace PropertyVisitor
{
	class GoldProperty;
	class SilverProperty;

	class PropertyVisitorBase
	{
	public:
		virtual ~PropertyVisitorBase()
		{
		}

		virtual void visit(GoldProperty & gold)
		{
		}
		virtual void visit(SilverProperty & gold)
		{
		}

	};

} // namespace PropertyVisitor
