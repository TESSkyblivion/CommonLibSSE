#include "RE/ActiveEffect.h"

#include "RE/Actor.h"
#include "RE/Effect.h"
#include "RE/Offsets.h"
#include "REL/Relocation.h"


namespace RE
{
	void ActiveEffect::Dispell(bool a_force)
	{
		using func_t = function_type_t<decltype(&ActiveEffect::Dispell)>;
		REL::Offset<func_t*> func(Offset::ActiveEffect::Dispell);
		return func(this, a_force);
	}


	EffectSetting* ActiveEffect::GetBaseObject()
	{
		return effect ? effect->baseEffect : 0;
	}


	const EffectSetting* ActiveEffect::GetBaseObject() const
	{
		return effect ? effect->baseEffect : 0;
	}


	NiPointer<Actor> ActiveEffect::GetCasterActor() const
	{
		return caster.get();
	}


	Actor* ActiveEffect::GetTargetActor()
	{
		if (target && target->MagicTargetIsActor()) {
			return static_cast<Actor*>(target);
		} else {
			return 0;
		}
	}


	const Actor* ActiveEffect::GetTargetActor() const
	{
		if (target && target->MagicTargetIsActor()) {
			return static_cast<const Actor*>(target);
		} else {
			return 0;
		}
	}
}
