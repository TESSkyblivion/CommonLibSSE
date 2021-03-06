#pragma once

#include "RE/FxDelegate.h"
#include "RE/FxDelegateHandler.h"


namespace RE
{
	class AddCallbackVisitor : public FxDelegateHandler::CallbackProcessor
	{
	public:
		inline static const void* RTTI = RTTI_AddCallbackVisitor;


		AddCallbackVisitor(FxDelegateHandler* a_handler, FxDelegate::CallbackHash* a_hash);
		virtual ~AddCallbackVisitor() = default;																// 00

		// override (FxDelegateHandler::CallbackProcessor)
		virtual void Process(const GString& a_methodName, FxDelegateHandler::CallbackFn* a_method) override;	// 01


		// members
		FxDelegateHandler*			handler;	// 08
		FxDelegate::CallbackHash*	hash;		// 10
	};
	STATIC_ASSERT(sizeof(AddCallbackVisitor) == 0x18);
}
