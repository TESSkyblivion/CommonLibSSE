#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class TESForm;


	class ExtraStartingWorldOrCell : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraStartingWorldOrCell;


		enum { kExtraTypeID = ExtraDataType::kStartingWorldOrCell };


		virtual ~ExtraStartingWorldOrCell();			// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kStartingWorldOrCell; }


		// members
		TESForm* startingWorldOrCell;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraStartingWorldOrCell) == 0x18);
}
