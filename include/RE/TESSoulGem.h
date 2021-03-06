#pragma once

#include "RE/FormTypes.h"
#include "RE/SoulLevels.h"
#include "RE/TESObjectMISC.h"


namespace RE
{
	class TESSoulGem : public TESObjectMISC
	{
	public:
		inline static const void* RTTI = RTTI_TESSoulGem;


		enum { kTypeID = FormType::SoulGem };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kCanHoldNPCSoul = 1 << 17
			};
		};


		virtual ~TESSoulGem();															// 00

		// override (TESObjectMISC)
		virtual void	InitializeData() override;										// 04
		virtual void	LoadRecordByType(TESFile* a_mod, UInt32 a_recordType) override;	// 54
		virtual void	Unk_55(void) override;											// 55

		SOUL_LEVEL	GetContainedSoul() const;
		SOUL_LEVEL	GetMaximumCapacity() const;


		// members
		TESSoulGem*	linkedSoulGem;	// 100 - NAM0
		SOUL_LEVEL	currentSoul;	// 108 - SOUL
		SOUL_LEVEL	soulCapacity;	// 109 - SLCP
		UInt16		unk10A;			// 10A
		UInt32		unk10C;			// 10C
	};
	STATIC_ASSERT(sizeof(TESSoulGem) == 0x110);
}
