#pragma once

#include "RE/BSIntrusiveRefCounted.h"
#include "RE/BSTArray.h"
#include "RE/FormTypes.h"
#include "RE/NiMatrix3.h"
#include "RE/NiPoint3.h"
#include "RE/TESBoundObject.h"
#include "RE/TESFullName.h"
#include "RE/TESModel.h"
#include "RE/TESProduceForm.h"


namespace RE
{
	struct OBJ_TREE	// CNAM
	{
		float	trunkFlexibility;	// 00
		float	branchFlexibility;	// 04
		float	trunkAmplitude;		// 08
		float	frontAmplitude;		// 0C
		float	backAmplitude;		// 10
		float	sideAmplitude;		// 14
		float	frontFrequency;		// 18
		float	backFrequency;		// 1C
		float	sideFrequency;		// 20
		float	leafFlexibility;	// 24
		float	leafAmplitude;		// 28
		float	leafFrequency;		// 2C
	};
	STATIC_ASSERT(sizeof(OBJ_TREE) == 0x30);


	struct BoneData
	{
		NiMatrix3	localBoneRotation;				// 00
		NiPoint3	worldBoneDir;					// 24
		UInt32		parentWorldBoneRotationIndex;	// 30
	};
	STATIC_ASSERT(sizeof(BoneData) == 0x34);


	struct BaseTreeData : public BSIntrusiveRefCounted
	{
		UInt32				pad04;						// 04
		BSTArray<BoneData>	branchBoneData;				// 08
		BSTArray<NiMatrix3>	parentWorldBoneRotations;	// 20
	};
	STATIC_ASSERT(sizeof(BaseTreeData) == 0x38);


	class TESObjectTREE :
		public TESBoundObject,	// 00
		public TESModel,		// 30
		public TESFullName,		// 58
		public TESProduceForm	// 68
	{
	public:
		inline static const void* RTTI = RTTI_TESObjectTREE;


		enum { kTypeID = FormType::Tree };


		enum class etTreeType : UInt32
		{
			kShortAndThin = 0,
			kShortAndThick = 1,
			kTallAndThin = 2,
			kTallAndThick = 3
		};


		struct RecordFlags
		{
			enum RecordFlag : UInt32
			{
				kDeleted = 1 << 5,
				kIgnored = 1 << 12,
				kHasDistantLOD = 1 << 15
			};
		};


		virtual ~TESObjectTREE();																															// 00

		// override (TESBoundObject)
		virtual void	InitializeData() override;																											// 04
		virtual bool	Load(TESFile* a_mod) override;																										// 06
		virtual void	InitItemImpl() override;																											// 13
		virtual bool	Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, UInt8 a_arg3, UInt64 a_arg4, SInt32 a_targetCount) override;	// 37
		virtual void	Unk_44(void) override;																												// 44
		virtual bool	GetCrosshairText(TESObjectREFR* a_ref, BSString* a_dst) override;																	// 4C
		virtual void	Unk_4F(void) override;																												// 4F
		virtual void	Unk_50(void) override;																												// 50 - { return; }
		virtual void	Unk_51(void) override;																												// 51 - { return; }
		virtual void	Unk_52(void) override;																												// 52 - { return; }


		// members
		OBJ_TREE		data;		// 88
		BaseTreeData*	baseData;	// B8
		etTreeType		type;		// C0
		UInt32			padC4;		// C4
	};
	STATIC_ASSERT(sizeof(TESObjectTREE) == 0xC8);
}
