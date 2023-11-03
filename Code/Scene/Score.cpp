#include "DxLib.h"
#include "Score.h"
#include"ConstVal.h"

Score::Score(int now_score)
{
	this->now_score = now_score;

	//FILE* fp_s;//ランキングの読み込み
	//fopen_s(&fp_t, treasure_data[stage_num], "r");

	//for (int i = 0; i < STAGE_BLOCK_NUM_Y; i++)
	//{
	//	for (int j = 0; j < stage_width; j++)
	//	{
	//		int block_type, treasure_type;
	//		fscanf_s(fp_s, "%d", &block_type);
	//		fscanf_s(fp_t, "%d", &treasure_type);

	//		DATA location;
	//		location.x = ((j - 1) * BLOCK_SIZE_X) + (BLOCK_SIZE_X / 2);
	//		location.y = (i * BLOCK_SIZE_Y) + (BLOCK_SIZE_Y / 2);

	//		if (block_type != -1)block.emplace_back(location, block_type);
	//		if (treasure_type == 5) flag_location = location;
	//		else if ((treasure_type != -1) && treasure_type != 0)treasure.emplace_back(location, treasure_type);
	//	}
	//}

	//fclose(fp_s);
	//fclose(fp_t);

}

void Score::Update()
{

}

void Score::Draw()
{
	DrawFormatString(WINDOW_X / 2, WINDOW_Y / 2, 0xffffff, "スコア　%d", now_score);
}