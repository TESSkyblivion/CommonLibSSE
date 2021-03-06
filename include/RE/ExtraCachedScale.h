#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class ExtraCachedScale : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraCachedScale;


		enum { kExtraTypeID = ExtraDataType::kCachedScale };


		virtual ~ExtraCachedScale();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kCachedScale; }


		// members
		float	scale3D;	// 10
		float	refScale;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraCachedScale) == 0x18);
}
