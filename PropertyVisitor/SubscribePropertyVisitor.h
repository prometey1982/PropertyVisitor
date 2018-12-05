#pragma once

#include "PropertyVisitorBase.h"

#include <unordered_map>
#include <functional>
#include <memory>
#include <type_traits>

namespace PropertyVisitor
{
	class Property;

	class SubscribePropertyVisitor : public PropertyVisitorBase
	{
	public:
		template<typename PropertyType>
		SubscribePropertyVisitor & on(std::function<void(PropertyType&)> func)
		{
			std::unique_ptr<CallbackBase> callback = std::make_unique<Callback<PropertyType> >(func);
			functions_[PropertyType::propertyName] = std::move(callback);
			return *this;
		}

		virtual void visit(GoldProperty & prop)
		{
			visit_impl<std::remove_reference<decltype(prop)>::type>(prop);
		}

		virtual void visit(SilverProperty & prop)
		{
			visit_impl<std::remove_reference<decltype(prop)>::type>(prop);
		}

	private:
		class CallbackBase
		{
		public:
			virtual ~CallbackBase()
			{
			}
		};

		template<typename PropertyType>
		class Callback : public CallbackBase
		{
		public:
			typedef std::function<void(PropertyType&)> CallbackFunctionT;

			explicit Callback(CallbackFunctionT function)
				: function_(function)
			{
			}

			Callback(const Callback & callback)
				: function_(callback.function_)
			{
			}

			virtual void operator()(PropertyType & prop)
			{
				function_(prop);
			}

		private:
			CallbackFunctionT function_;
		};

		template<typename PropertyType>
		void visit_impl(PropertyType & prop)
		{
			auto callback = functions_.find(PropertyType::propertyName);
			if (callback != functions_.end())
				(*static_cast<Callback<PropertyType> *>(callback->second.get()))(prop);
		}

	private:
		std::unordered_map<std::string, std::unique_ptr<CallbackBase> > functions_;
	};

} // namespace PropertyVisitor
