#pragma once
#include "TypeNull.h"
#include "TypeNormal.h"
#include "TypeFire.h"
#include "TypeWater.h"
#include "TypeGrass.h"
#include "TypeElectric.h"
#include "TypeIce.h"
#include "TypeFighting.h"
#include "TypePoison.h"
#include "TypeGround.h"
#include "TypeFlying.h"
#include "TypePsychic.h"
#include "TypeBug.h"
#include "TypeRock.h"
#include "TypeGhost.h"
#include "TypeDragon.h"
#include "TypeDark.h"
#include "TypeSteel.h"
#include "TypeFairy.h"

class CTypeFactory
{
public:
	CTypeBase* CreateType(TypeNo no)
	{
		switch (no)
		{
		case TYPE0_NULL:
			return new CTypeNull;
		case TYPE1_NORMAL:
			return new CTypeNormal;
		case TYPE2_FIRE:
			return new CTypeFire;
		case TYPE3_WATER:
			return new CTypeWater;
		case TYPE4_GRASS:
			return new CTypeGrass;
		case TYPE5_ELECTRIC:
			return new CTypeElectric;
		case TYPE6_ICE:
			return new CTypeIce;
		case TYPE7_FIGHTING:
			return new CTypeFighting;
		case TYPE8_POISON:
			return new CTypePoison;
		case TYPE9_GROUND:
			return new CTypeGround;
		case TYPE10_FLYING:
			return new CTypeFlying;
		case TYPE11_PSYCHIC:
			return new CTypePsychic;
		case TYPE12_BUG:
			return new CTypeBug;
		case TYPE13_ROCK:
			return new CTypeRock;
		case TYPE14_GHOST:
			return new CTypeGhost;
		case TYPE15_DRAGON:
			return new CTypeDragon;
		case TYPE16_DARK:
			return new CTypeDark;
		case TYPE17_STEEL:
			return new CTypeSteel;
		case TYPE18_FAIRY:
			return new TypeFairy;
		default:
			return new CTypeNormal;
		}
		return new CTypeNormal;
	}

	CTypeBase* CreateType(int no)
	{
		switch (no)
		{
		case 0:
			return new CTypeNull;
		case 1:
			return new CTypeNormal;
		case 2:
			return new CTypeFire;
		case 3:
			return new CTypeWater;
		case 4:
			return new CTypeGrass;
		case 5:
			return new CTypeElectric;
		case 6:
			return new CTypeIce;
		case 7:
			return new CTypeFighting;
		case 8:
			return new CTypePoison;
		case 9:
			return new CTypeGround;
		case 10:
			return new CTypeFlying;
		case 11:
			return new CTypePsychic;
		case 12:
			return new CTypeBug;
		case 13:
			return new CTypeRock;
		case 14:
			return new CTypeGhost;
		case 15:
			return new CTypeDragon;
		case 16:
			return new CTypeDark;
		case 17:
			return new CTypeSteel;
		case 18:
			return new TypeFairy;
		default:
			return new CTypeNormal;
		}
		return new CTypeNormal;
	}
};