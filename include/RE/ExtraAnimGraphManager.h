#pragma once

#include "RE/BSExtraData.h"
#include "RE/BSTSmartPointer.h"
#include "RE/ExtraDataTypes.h"


namespace RE
{
	class BSAnimationGraphManager;


	class ExtraAnimGraphManager : public BSExtraData
	{
	public:
		inline static const void* RTTI = RTTI_ExtraAnimGraphManager;


		enum { kExtraTypeID = ExtraDataType::kAnimGraphManager };


		virtual ~ExtraAnimGraphManager();				// 00

		// override (BSExtraData)
		virtual ExtraDataType GetType() const override;	// 01 - { return kAnimGraphManager; }


		// members
		BSTSmartPointer<BSAnimationGraphManager> animGraphMgr;	// 10
	};
	STATIC_ASSERT(sizeof(ExtraAnimGraphManager) == 0x18);
}
