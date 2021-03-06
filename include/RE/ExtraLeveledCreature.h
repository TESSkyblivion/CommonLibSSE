#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/FormTypes.h"


namespace RE
{
	class ExtraLeveledCreature : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraLeveledCreature;


		enum { kExtraTypeID = ExtraDataType::kLeveledCreature };


		virtual ~ExtraLeveledCreature();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kLeveledCreature; }


		// members
		TESActorBase*	originalBase;	// 10
		TESActorBase*	templateBase;	// 18
	};
	STATIC_ASSERT(sizeof(ExtraLeveledCreature) == 0x20);
}
