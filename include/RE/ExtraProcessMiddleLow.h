#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraProcessMiddleLow : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraProcessMiddleLow;


		enum { kExtraTypeID = ExtraDataType::kProcessMiddleLow };


		virtual ~ExtraProcessMiddleLow();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kProcessMiddleLow; }


		// members
		UInt32	refCount;	// 10
		UInt32	pad14;		// 14
	};
	STATIC_ASSERT(sizeof(ExtraProcessMiddleLow) == 0x18);
}
