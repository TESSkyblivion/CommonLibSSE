#pragma once

#include "RE/FormTypes.h"
#include "RE/TESForm.h"


namespace RE
{
	class TESCondition;


	class BGSStoryManagerTreeForm : public TESForm
	{
	public:
		inline static const void* RTTI = RTTI_BGSStoryManagerTreeForm;


		virtual ~BGSStoryManagerTreeForm();								// 00

		// add
		virtual UInt32						GetNumChildren() const;		// 3B - { return 0; }
		virtual BGSStoryManagerEventNode*	GetNthChild(UInt32 a_idx);	// 3C - { return 0; }
		virtual TESCondition*				GetConditions() = 0;		// 3D
		virtual void						Unk_3E(void) = 0;			// 3E


		// members
		UInt32	lastVisitorID;	// 20
		UInt32	pad24;			// 24
	};
	STATIC_ASSERT(sizeof(BGSStoryManagerTreeForm) == 0x28);
}
