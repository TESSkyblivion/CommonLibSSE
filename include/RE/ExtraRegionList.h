#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class TESRegionList;


	class ExtraRegionList : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraRegionList;


		enum { kExtraTypeID = ExtraDataType::kRegionList };


		virtual ~ExtraRegionList();						// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kRegionList; }


		// members
		TESRegionList* list;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraRegionList) == 0x18);
}
