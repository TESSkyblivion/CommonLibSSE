#pragma once

#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSPickupPutdownSounds.h"
#include "RE/SpellItem.h"
#include "RE/TESModelTextureSwap.h"
#include "RE/TESValueForm.h"
#include "RE/TESWeightForm.h"


namespace RE
{
	class ScrollItem :
		public SpellItem,					// 000
		public TESModelTextureSwap,			// 0E8
		public BGSDestructibleObjectForm,	// 120
		public BGSPickupPutdownSounds,		// 130
		public TESWeightForm,				// 148
		public TESValueForm					// 158
	{
	public:
		inline static const void* RTTI = RTTI_ScrollItem;


		enum { kTypeID = FormType::Scroll };


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		virtual ~ScrollItem();																		// 00

		// override (SpellItem)
		virtual void						InitItemImpl() override;								// 13
		virtual MagicSystem::SpellType		GetSpellType() const override;							// 53 - { return MagicSystem::SpellType::kScroll; }
		virtual MagicSystem::CastingType	GetCastingType() const override;						// 55 - { return MagicSystem::CastingType::kFireAndForget; }
		virtual void						Unk_60(void) override;									// 60 - { return 0; }
		virtual ActorValue					GetActorValueType() const override;						// 66 - { return ActorValue::kNone; }
		virtual void						LoadData(TESFile* a_mod, UInt32 a_signature) override;	// 6A
	};
	STATIC_ASSERT(sizeof(ScrollItem) == 0x168);
}
