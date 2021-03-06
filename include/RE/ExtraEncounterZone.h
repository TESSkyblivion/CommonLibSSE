#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class BGSEncounterZone;


	class ExtraEncounterZone : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraEncounterZone;


		enum { kExtraTypeID = ExtraDataType::kEncounterZone };


		virtual ~ExtraEncounterZone();													// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kEncounterZone; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return zone != a_rhs->zone; }


		// members
		BGSEncounterZone* zone;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraEncounterZone) == 0x18);
}
