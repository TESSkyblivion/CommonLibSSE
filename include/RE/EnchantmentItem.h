#pragma once

#include "RE/FormTypes.h"
#include "RE/MagicItem.h"
#include "RE/MagicSystem.h"


namespace RE
{
	class EnchantmentItem : public MagicItem
	{
	public:
		inline static const void* RTTI = RTTI_EnchantmentItem;


		enum { kTypeID = FormType::Enchantment };


		enum class EnchantmentFlag : UInt32
		{
			kNone = 0,
			kCostOverride = 1 << 0,
			kFoodItem = 1 << 1,
			kExtendDuration = 1 << 3
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12
			};
		};


		struct Data	// ENIT
		{
			SInt32						costOverride;		// 00
			EnchantmentFlag				flags;				// 04
			MagicSystem::CastingType	castingType;		// 08
			SInt32						chargeOverride;		// 0C
			MagicSystem::Delivery		delivery;			// 10
			MagicSystem::SpellType		spellType;			// 14
			float						chargeTime;			// 18
			UInt32						pad1C;				// 1C
			EnchantmentItem*			baseEnchantment;	// 20
			BGSListForm*				wornRestrictions;	// 28
		};
		STATIC_ASSERT(sizeof(Data) == 0x30);


		virtual ~EnchantmentItem();																		// 00

		// override (MagicItem)
		virtual void						InitializeData() override;									// 04
		virtual void						ClearData() override;										// 05
		virtual void						InitItemImpl() override;									// 13
		virtual MagicSystem::SpellType		GetSpellType() const override;								// 53 - { return data.spellType; }
		virtual void						SetCastingType(MagicSystem::CastingType a_type) override;	// 54 - { data.castingType = a_type; }
		virtual MagicSystem::CastingType	GetCastingType() const override;							// 55 - { return data.castingType; }
		virtual void						SetDeliveryType(MagicSystem::Delivery a_type) override;		// 56 - { if (Unk_58()) { data.delivery = a_type; } }
		virtual MagicSystem::Delivery		GetDeliveryType() const override;							// 57 - { return data.delivery; }
		virtual float						GetChargeTime() const override;								// 64
		virtual ActorValue					GetActorValueType() const override;							// 66 - { return ActorValue::kEnchanting; }
		virtual UInt32						GetDataSigniture() const override;							// 68 - { return 'ENIT'; }
		virtual void						CopyData(MagicItem* a_src) override;						// 69
		virtual void*						GetData() override;											// 6C - { return &data; }
		virtual const void*					GetData() const override;									// 6D - { return &data; }
		virtual UInt32						GetDataSize() const override;								// 6E - { return 0x30; }
		virtual void						LoadData(TESFile* a_mod) override;							// 6F
		virtual void						ByteSwapData() override;									// 70


		// members
		Data data;	// 90 - ENIT
	};
	STATIC_ASSERT(sizeof(EnchantmentItem) == 0xC0);
}
