#pragma once

typedef struct tag_AdditionalEffect
{
	bool Subject;	// 追加効果の対象
	int  EffectNo;  // 効果の番号
	int  EffectPower; // 効果の威力
	int  ActivatePercent; // 発動確率
}AdditionalEffect;