#pragma once


namespace RE
{
	class IAIWorldLocation;
	class PackageLocation;
	class TESObjectREFR;
	struct AIWorldLocationContext;


	class IAIWorldLocationHandle
	{
	public:
		inline static const void* RTTI = RTTI_IAIWorldLocationHandle;


		virtual ~IAIWorldLocationHandle();																				// 00

		// add
		virtual const IAIWorldLocation*	AllocateLocation(AIWorldLocationContext* a_context) = 0;						// 01
		virtual PackageLocation*		GetAsPackageLocation();															// 02 - { return 0; }
		virtual bool					IsRefAtLocation(AIWorldLocationContext* a_context, TESObjectREFR* a_ref) = 0;	// 03
	};
	STATIC_ASSERT(sizeof(IAIWorldLocationHandle) == 0x8);
}
