#pragma once


namespace RE
{
	class BGSLoadFormBuffer;
	class BGSSaveFormBuffer;
	class TESForm;


	class TESPackageData
	{
	public:
		inline static const void* RTTI = RTTI_TESPackageData;


		virtual ~TESPackageData();											// 00

		// add
		virtual void	Copy(TESPackageData* a_package, TESForm* a_form);	// 01 - { return; }
		virtual bool	Compare(TESPackageData* a_package);					// 02 - { return true; }
		virtual void	InitItem(TESForm* a_form);							// 03 - { return; }
		virtual void	SaveGame(BGSSaveFormBuffer* a_buf);					// 04 - { return; }
		virtual void	LoadGame(BGSLoadFormBuffer* a_buf);					// 05 - { return; }
	};
	STATIC_ASSERT(sizeof(TESPackageData) == 0x8);
}
