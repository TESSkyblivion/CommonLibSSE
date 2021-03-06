#pragma once

#include "RE/BSExtraData.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class BSOcclusionShape;


	class ExtraOcclusionShape : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraOcclusionShape;


		enum { kExtraTypeID = ExtraDataType::kOcclusionShape };


		virtual ~ExtraOcclusionShape();					// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kOcclusionShape; }


		// members
		NiPointer<BSOcclusionShape> shape;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraOcclusionShape) == 0x18);
}
