#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSPointerHandle.h"
#include "RE/ExtraDataTypes.h"
#include "RE/NiSmartPointer.h"


namespace RE
{
	class TESObjectREFR;


	class ExtraReferenceHandle : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraReferenceHandle;


		enum { kExtraTypeID = ExtraDataType::kReferenceHandle };


		ExtraReferenceHandle();
		explicit ExtraReferenceHandle(ObjectRefHandle a_originalRef);
		virtual ~ExtraReferenceHandle() = default;											// 00

		// override (BSExtraData)
		virtual ExtraDataType		GetType() const override;								// 01 - { return kReferenceHandle; }
		virtual bool				IsNotEqual(const BSExtraData* a_rhs) const override;	// 02 - { return originalRef != a_rhs->originalRef; }

		NiPointer<TESObjectREFR> GetOriginalReference();


		// members
		ObjectRefHandle	originalRef;	// 10
		UInt32			pad14;			// 14
	};
	STATIC_ASSERT(sizeof(ExtraReferenceHandle) == 0x18);
}
