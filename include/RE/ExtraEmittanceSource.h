#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class TESForm;


	class ExtraEmittanceSource : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraEmittanceSource;


		enum { kExtraTypeID = ExtraDataType::kEmittanceSource };


		virtual ~ExtraEmittanceSource();												// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kEmittanceSource; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return source != a_rhs->source; }


		// members
		TESForm* source;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraEmittanceSource) == 0x18);
}
