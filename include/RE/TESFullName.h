#pragma once

#include "RE/BaseFormComponent.h"
#include "RE/BSFixedString.h"


namespace RE
{
	class TESFullName : public BaseFormComponent
	{
	public:
		inline static const void* RTTI = RTTI_TESFullName;


		virtual ~TESFullName();

		// override (BaseFormComponent)
		virtual void		InitializeDataComponent() override;					// 01 - { name = ""; }
		virtual void		ClearDataComponent() override;						// 02 - { return; }
		virtual void		CopyComponent(BaseFormComponent* a_rhs) override;	// 03

		// add
		virtual UInt32		GetFullNameLength() const;							// 04
		virtual const char*	GetFullName() const;								// 05


		// members
		BSFixedString fullName;	// 08 - FULL
	};
	STATIC_ASSERT(sizeof(TESFullName) == 0x10);
}
