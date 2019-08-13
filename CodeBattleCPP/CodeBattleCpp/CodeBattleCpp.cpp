#include <iostream>
#include <random>

#include "GameClientLodeRunner.h"

	/*
	 !!!!!��������!!!!!
		��������� ���������� ������ � Microsoft Visual Studio 2017
		���� ��� ������ ��������� ������ ���� 
		The Windows SDK version 10.0.16299.0 was not found...
		������ ���������:
			1)������ ������� ���� �� CodeBattleCpp � ��� �� properties.
			2)������� Configuration Properties->General
			3)������� Windows SDK Version � ����� ��������� � ���������� ������
			4)�������� Apply
			5)��������� ���� ����� � CodeBattleCppLibrary
	*/


void main()
{
	srand(time(0));
	/*
	 ����� ����������� ��� �������� �� �������� � ������ � ������� �������.
	 URL ����� �������� �����: http://localhost:8888/codenjoy-contest/board/player/cg601yim3186cotnftue?code=8887669793631271133&gameName=loderunner
	 �� url ����:
	 ����� ������� = localhost:8888
	 id ������������ = cg601yim3186cotnftue
	 ��� ������������ = 8887669793631271133
	 
	 ����������� �� ���:
		GameClientLodeRunner *gcb = new GameClientLodeRunner("localhost:8888", "cg601yim3186cotnftue", "8887669793631271133")
	*/
	GameClientLodeRunner *gcb = new GameClientLodeRunner("����� �������", "id ������������", "��� ������������");
	gcb->Run([&]()
	{
		LodeRunnerBlocks **map = gcb->get_map();
		/*
		 ����� ��� ����� 
		 ������ �������
			 gcb->Blank() - ������ �� ������
			 gcb->Act() - �������� ����
			 gcb->get_map() - �������� �����
			 �������� ��������:
			 gcb->Up() 
			 gcb->Down()
			 gcb->Left()
			 gcb->Right()
			 ���� ����� ������� �������� � ����������� ����� �.�. �������� ���� (LEFT, ACT), �� �������� ������ ���
			 gcb->Up(PlayerAction::ACT)
			 gcb->Down(PlayerAction::ACT)
			 gcb->Left(PlayerAction::ACT)
			 gcb->Right(PlayerAction::ACT)
			 �� ������� � ������ ����� PlayerAction::None

			 ����� ����� ������ �� ����� �.�. ��� �������� ��������� ������ ���� �������� ���� �� ���.
			 ��� ������ ������� Up(), Down(), Left(), Right(), Act() ��� ����� �������� �������� �� ������.
			 ����� ����� ���������� ������ ���� �� ������� � ��(������) ���������� ����� ��������� ���� �.�.
			 �� ����� ��� � �����. 

		*/

		bool done = false;

		switch (rand() % 5)
		{
			case 0: gcb->Up(PlayerAction::ACT); done = true;
			case 1: gcb->Down(PlayerAction::ACT); done = true;
			case 2: gcb->Left(PlayerAction::ACT); done = true;
			case 3: gcb->Right(PlayerAction::ACT); done = true;
			case 4: gcb->Act(); done = true;
		}


		if (done == false)
			gcb->Blank();
	});

	getchar();
}
