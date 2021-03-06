#pragma once

#include "RE/BGSDestructibleObjectForm.h"
#include "RE/BGSEquipType.h"
#include "RE/BGSMessageIcon.h"
#include "RE/BGSPickupPutdownSounds.h"
#include "RE/FormTypes.h"
#include "RE/MagicItem.h"
#include "RE/TESIcon.h"
#include "RE/TESModelTextureSwap.h"
#include "RE/TESWeightForm.h"


namespace RE
{
	class AlchemyItem :
		public MagicItem,					// 000
		public TESModelTextureSwap,			// 090
		public TESIcon,						// 0C8
		public BGSMessageIcon,				// 0D8
		public TESWeightForm,				// 0F0
		public BGSEquipType,				// 100
		public BGSDestructibleObjectForm,	// 110
		public BGSPickupPutdownSounds		// 120
	{
	public:
		inline static const void* RTTI = RTTI_AlchemyItem;


		enum { kTypeID = FormType::AlchemyItem };


		enum class AlchemyFlag : UInt32
		{
			kNone = 0,
			kCostOverride = 1 << 0,
			kFoodItem = 1 << 1,
			kExtendDuration = 1 << 3,
			kMedicine = 1 << 16,
			kPoison = 1 << 17
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kMedicine = 1 << 29
			};
		};


		struct Data	// ENIT
		{
			SInt32					costOverride;		// 00
			AlchemyFlag				flags;				// 04
			SpellItem*				addictionItem;		// 08
			float					addictionChance;	// 10
			UInt32					pad14;				// 14
			BGSSoundDescriptorForm*	consumptionSound;	// 18
		};
		STATIC_ASSERT(sizeof(Data) == 0x20);


		virtual ~AlchemyItem();																		// 00

		// override (MagicItem)
		virtual void						InitializeData() override;								// 04
		virtual void						ClearData() override;									// 05
		virtual void						InitItemImpl() override;								// 13
		virtual MagicSystem::SpellType		GetSpellType() const override;							// 53 - { return MagicType::kAlchemy; }
		virtual MagicSystem::CastingType	GetCastingType() const override;						// 55 - { return CastType::kFireAndForget; }
		virtual MagicSystem::Delivery		GetDeliveryType() const override;						// 57 - { return TargetType::kSelf; }
		virtual bool						IsFoodItem() const override;							// 5D - { return ((GetData()->flags) & 2) && !IsPoison(); }
		virtual bool						IsPoison() const override;								// 61 - { return ((GetData()->flags) >> 17) & 1; }
		virtual bool						IsHealingItem() const override;							// 62 - { return ((GetData()->flags) >> 8) >> 8; }
		virtual ActorValue					GetActorValueType() const override;						// 66 - { return ActorValue::kConfidence; }
		virtual UInt32						GetDataSigniture() const override;						// 68 - { return 'ENIT'; }
		virtual void						CopyData(MagicItem* a_src) override;					// 69
		virtual void						LoadData(TESFile* a_mod, UInt32 a_signature) override;	// 6A
		virtual void*						GetData() override;										// 6C - { return &effectData; }
		virtual const void*					GetData() const override;								// 6D - { return &effectData; }
		virtual UInt32						GetDataSize() const override;							// 6E - { return 0x20; }
		virtual void						LoadData(TESFile* a_mod) override;						// 6F
		virtual void						ByteSwapData() override;								// 70


		// members
		Data	data;			// 138 - ENIT
		TESIcon	messageIcon;	// 158
	};
	STATIC_ASSERT(sizeof(AlchemyItem) == 0x168);
}
