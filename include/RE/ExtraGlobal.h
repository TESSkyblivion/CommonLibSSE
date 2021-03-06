#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class TESGlobal;


	class ExtraGlobal : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraGlobal;


		enum { kExtraTypeID = ExtraDataType::kGlobal };


		virtual ~ExtraGlobal();															// 00

		// override (BSExtraData)
		virtual ExtraDataType	GetType() const override;								// 01 - { return kGlobal; }
		virtual bool			IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return global != a_rhs->global; }


		// members
		TESGlobal* global;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraGlobal) == 0x18);
}
