#pragma once
#include "Attack_Type_CS.h"
#include "Fly_Type_CS.h"

class Roles_CS
{
public:
	Roles_CS();
	Roles_CS(Attack_Type_CS *temp_Attack_pr, Fly_Type_CS *temp_Fly_pr);
	void    Attack_Fn();
	void    Fly_Fn();
	void    Set_Attack_Type_Fn(Attack_Type_CS *temp_Attack_type_pr);
	void    Set_Fly_Type_Fn(Fly_Type_CS *temp_Fly_type_pr);

protected:
	Attack_Type_CS     *m_Attack_Type_cs_pr;  // �Ҷq�쩹��i�H�ݭn�^���s�[�J�������覡�A�ҥH�N���������W�ߥX�ӥt�~�ʸ˦�class
	Fly_Type_CS        *m_Fly_Type_cs_pr;     // �Ҷq�I�P�W�p�P
};


class Warrior_CS :public Roles_CS
{
public:
	Warrior_CS();
	Warrior_CS(Attack_Type_CS *temp_Attack_pr, Fly_Type_CS *temp_Fly_pr);
};

class DragonRidor_CS :public Roles_CS
{
public:
	DragonRidor_CS();
	DragonRidor_CS(Attack_Type_CS *temp_Attack_pr, Fly_Type_CS *temp_Fly_pr);
};
