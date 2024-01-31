#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>

using namespace std;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

char arr[102][102];

class player {
public:
	int spawnX, spawnY;
	int curX, curY;
	int hp, max_hp;
	int lev;
	int atk, def;
	int exp;
	int weapon, armor;
	set<string>aces;
public:
	player(int x, int y) {
		this->spawnX = x, this->spawnY = y;
		this->curX = x, this->curY = y;
		this->hp = 20, this->max_hp = 20;
		this->atk = 2, this->def = 2;
		this->lev = 1;
		this->exp = 0;
		this->weapon = 0, this->armor = 0;
	}

	bool hasEffecf(string s) {
		if (this->aces.find(s) != this->aces.end()) {
			return true;
		}
		return false;
	}

	void deleteEffect(string s) {
		s.erase(s.find(s));
	}

	void healHp(int n) {
		if (this->hp + n > this->max_hp)
			this->hp = max_hp;
		else
			this->hp += n;
	}

	void levelup() {
		int exp = this->exp, lev = this->lev;
		if (exp >= lev * 5) {
			this->lev+=1;
			this->atk += 2, this->def += 2;
			this->max_hp += 5;
			this->exp = 0;
			this->hp = this->max_hp;
			return;
		}
		else return;
	}
};

class monster {
public:
	int x, y;
	string name;
	int atk, def, exp;
	int hp, max_hp;
public:
	monster(int x, int y,string name, int W, int A, int H, int E ) {
		this->x = x, this->y = y;
		this->name = name;
		this->atk = W, this->def = A;
		this->hp = H, this->max_hp = H;
		this->exp = E;
	}
};

class itembox {
public:
	int x, y;
	char weaponType;
	int num;
	string effect;
public:
	itembox() {

	}
	
	itembox(int x, int y, char WT, int num) {
		this->x = x, this->y = y;
		this->weaponType = WT;
		this->num = num;
	}

	itembox(int x, int y, char WT, string  effect) {
		this->x = x, this->y = y;
		this->weaponType = WT;
		this->effect = effect;
	}
};

int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };

bool isRevive(player& p) { //true 부활 false 죽음
	bool RE = p.hasEffecf("RE");
	if (RE) {
		auto iter = p.aces.find("RE");
		p.aces.erase(iter);
		p.curX = p.spawnX;
		p.curY = p.spawnY;
		p.hp = p.max_hp;
		return true;
	}
	else {
		p.hp = 0;
		return false;
	}
}

bool isDiedByTrap(player& p) { //false 안죽음, true 죽음
	bool DX = p.hasEffecf("DX");
	if (DX) {
		if (p.hp - 1 > 0) {
			p.hp -= 1;
			return false;
		}
		else { // 죽음
			p.hp = 0;
			return true;
		}
	}
	else {
		if (p.hp - 5 > 0) {
			p.hp -= 5;
			return false;
		}
		else {
			p.hp = 0;
			return	true;
		}
	}
}

void getItemBox(player& p, itembox& item) {
	char WT = item.weaponType;
	if (WT == 'O') {
		string effect = item.effect;
		if (p.aces.size() < 4 && !p.hasEffecf(effect)) 
			p.aces.insert(effect);
		else
			return;
	}
	else if (WT == 'W') 
		p.weapon = item.num;
	else
		p.armor = item.num;
}


int fightWithMonster(player& p, monster& m) { // 0리턴 플레이어 이김, 1 리턴 플레이어 죽음, -1 리턴 플레이어 부활

	int m_hp = m.hp, m_atk = m.atk, m_def = m.def, m_exp = m.exp;

	bool HR = p.hasEffecf("HR");
	bool RE = p.hasEffecf("RE");
	bool CO = p.hasEffecf("CO");
	bool EX = p.hasEffecf("EX");
	bool DX = p.hasEffecf("DX");

	int p_hp = p.hp, p_totalAD = p.atk + p.weapon, p_def = p.def + p.armor;

	int MtoP = max(1, m_atk - p_def); //몬스터 플레이어 평타
	int PtoM = max(1, p_totalAD - m_def);
	int firstAttack;
	if (CO && DX) {
		firstAttack = max(1, p_totalAD * 3 - m_def);
		if (m_hp - firstAttack <= 0) { //플레이어 win
			p.hp = p_hp;

			if (HR)
				p.healHp(3);

			if (EX)
				m_exp = m_exp * 1.2;
			
			p.exp += m_exp;

			p.levelup(); //레벨 업 여부

			return 0;
		}
		else { //몬스터가 때릴 차례
			m_hp -= firstAttack;

			if (p_hp - MtoP > 0) { //이제 평타 대전
				p_hp -= MtoP;
				int f = 0; // 0이면 플레이어 승리, 1이면 패배
				while (1) {
					m_hp -= PtoM;
					if (m_hp <= 0)
						break;
					p_hp -= MtoP;
					if (p_hp <= 0) {
						f = 1;
						break;
					}
				}
				if (!f) {
					p.hp = p_hp;

					if (HR)
						p.healHp(3);

					if (EX)
						m_exp = m_exp * 1.2;
					p.exp += m_exp;

					p.levelup(); //레벨 업 여부

					return 0;
				}
				else { //플레이어 사망
					if (isRevive(p)) {
						m.hp = m.max_hp;
						return -1;
					}
					else {
						return 1;
					}
				}
			}
			else { //플레이어 사망
				if (isRevive(p)) {
					m.hp = m.max_hp;
					return -1;
				}
				else {
					return 1;
				}
			}
		}
	}
	else if (CO) {
		firstAttack = max(1, p_totalAD * 2 - m_def);
		if (m_hp - firstAttack <= 0) { //플레이어 win
			p.hp = p_hp;

			if (HR)
				p.healHp(3);

			if (EX)
				m_exp = m_exp * 1.2;
			p.exp += m_exp;

			p.levelup(); //레벨 업 여부

			return 0;
		}
		else { //몬스터 차례
			m_hp -= firstAttack;

			if (p_hp - MtoP > 0) { //이제 평타 대전
				p_hp -= MtoP;
				int f = 0; // 0이면 플레이어 승리, 1이면 패배
				while (1) {
					m_hp -= PtoM;
					if (m_hp <= 0)
						break;
					p_hp -= MtoP;
					if (p_hp <= 0) {
						f = 1;
						break;
					}
				}
				if (!f) {
					p.hp = p_hp;

					if (HR)
						p.healHp(3);

					if (EX)
						m_exp = m_exp * 1.2;
					p.exp += m_exp;

					p.levelup(); //레벨 업 여부

					return 0;
				}
				else { //플레이어 사망
					if (isRevive(p)) {
						m.hp = m.max_hp;
						return -1;
					}
					else {
						return 1;
					}
				}
			}
			else { //플레이어 사망
				if (isRevive(p)) {
					m.hp = m.max_hp;
					return -1;
				}
				else {
					return 1;
				}
			}
		}
	}
	else {
		int f = 0;
		while (1) {
			m_hp -= PtoM;
			if (m_hp <= 0)
				break;
			p_hp -= MtoP;
			if (p_hp <= 0) {
				f = 1;
				break;
			}
		}
		if (!f) {
			p.hp = p_hp;

			if (HR)
				p.healHp(3);

			if (EX)
				m_exp = m_exp * 1.2;
			p.exp += m_exp;

			p.levelup(); //레벨 업 여부

			return 0;
		}
		else { //플레이어 사망
			if (isRevive(p)) {
				m.hp = m.max_hp;
				return -1;
			}
			else {
				return 1;
			}
		}
	}
}

int fightWithBoss(player& p, monster& m) { // 0리턴 플레이어 이김, 1 리턴 플레이어 죽음, -1 리턴 플레이어 부활

	int m_hp = m.hp, m_atk = m.atk, m_def = m.def, m_exp = m.exp;

	bool HR = p.hasEffecf("HR");
	bool RE = p.hasEffecf("RE");
	bool CO = p.hasEffecf("CO");
	bool EX = p.hasEffecf("EX");
	bool DX = p.hasEffecf("DX");
	bool HU = p.hasEffecf("HU");

	int p_hp = p.hp, p_totalAD = p.atk + p.weapon, p_def = p.def + p.armor;

	int MtoP = max(1, m_atk - p_def); //몬스터 플레이어 평타
	int PtoM = max(1, p_totalAD - m_def);
	int firstAttack;
	int bossFirstAttack;
	if (CO && DX && HU) {
		firstAttack=max(1, p_totalAD*3-m_def);
		p.hp = p.max_hp;
		p_hp = p.hp;
		if (m_hp - firstAttack <= 0) { //플레이어 win
			p.hp = p_hp;

			if (HR)
				p.healHp(3);

			if (EX)
				m_exp = m_exp * 1.2;
			p.exp += m_exp;

			p.levelup(); //레벨 업 여부

			return 0;
		}
		else { //평타 대전
			m_hp -= firstAttack;
			int f = 0;
			while (1) {
				m_hp -= PtoM;
				if (m_hp <= 0)
					break;
				p_hp -= MtoP;
				if (p_hp <= 0) {
					f = 1;
					break;
				}
			}
			if (!f) {
				p.hp = p_hp;

				if (HR)
					p.healHp(3);

				if (EX)
					m_exp = m_exp * 1.2;
				p.exp += m_exp;

				p.levelup(); //레벨 업 여부

				return 0;
			}
			else { //플레이어 사망
				if (isRevive(p)) {
					m.hp = m.max_hp;
					return -1;
				}
				else {
					return 1;
				}
			}
		}
	}
	else if (CO && DX) {
		firstAttack = max(1, p_totalAD * 3 - m_def);
		if (m_hp - firstAttack <= 0) { //플레이어 win
			p.hp = p_hp;

			if (HR)
				p.healHp(3);

			if (EX)
				m_exp = m_exp * 1.2;
			p.exp += m_exp;

			p.levelup(); //레벨 업 여부

			return 0;
		}
		else { //몬스터가 때릴 차례
			m_hp -= firstAttack;

			if (p_hp - MtoP > 0) { //이제 평타 대전
				p_hp -= MtoP;
				int f = 0; // 0이면 플레이어 승리, 1이면 패배
				while (1) {
					m_hp -= PtoM;
					if (m_hp <= 0)
						break;
					p_hp -= MtoP;
					if (p_hp <= 0) {
						f = 1;
						break;
					}
				}
				if (!f) {
					p.hp = p_hp;

					if (HR)
						p.healHp(3);

					if (EX)
						m_exp = m_exp * 1.2;
					p.exp += m_exp;

					p.levelup(); //레벨 업 여부

					return 0;
				}
				else { //플레이어 사망
					if (isRevive(p)) {
						m.hp = m.max_hp;
						return -1;
					}
					else {
						return 1;
					}
				}
			}
			else { //플레이어 사망
				if (isRevive(p)) {
					m.hp = m.max_hp;
					return -1;
				}
				else {
					return 1;
				}
			}
		}
	}
	else if (CO && HU) {
		firstAttack = max(1, p_totalAD * 2 - m_def);
		p.hp = p.max_hp;
		p_hp = p.hp;
		
		if (m_hp - firstAttack <= 0) { //플레이어 win
			p.hp = p_hp;

			if (HR)
				p.healHp(3);

			if (EX)
				m_exp = m_exp * 1.2;
			p.exp += m_exp;

			p.levelup(); //레벨 업 여부

			return 0;
		}
		else { //평타 대전
			m_hp -= firstAttack;
			int f = 0;
			while (1) {
				m_hp -= PtoM;
				if (m_hp <= 0)
					break;
				p_hp -= MtoP;
				if (p_hp <= 0) {
					f = 1;
					break;
				}
			}
			if (!f) {
				p.hp = p_hp;

				if (HR)
					p.healHp(3);

				if (EX)
					m_exp = m_exp * 1.2;
				p.exp += m_exp;

				p.levelup(); //레벨 업 여부

				return 0;
			}
			else { //플레이어 사망
				if (isRevive(p)) {
					m.hp = m.max_hp;
					return -1;
				}
				else {
					return 1;
				}
			}
		}
	}
	else if (CO) {
		firstAttack = max(1, p_totalAD * 2 - m_def);
		if (m_hp - firstAttack <= 0) { //플레이어 win
			p.hp = p_hp;

			if (HR)
				p.healHp(3);

			if (EX)
				m_exp = m_exp * 1.2;
			p.exp += m_exp;

			p.levelup(); //레벨 업 여부

			return 0;
		}
		else { //몬스터 차례
			m_hp -= firstAttack;

			if (p_hp - MtoP > 0) { //이제 평타 대전
				p_hp -= MtoP;
				int f = 0; // 0이면 플레이어 승리, 1이면 패배
				while (1) {
					m_hp -= PtoM;
					if (m_hp <= 0)
						break;
					p_hp -= MtoP;
					if (p_hp <= 0) {
						f = 1;
						break;
					}
				}
				if (!f) {
					p.hp = p_hp;

					if (HR)
						p.healHp(3);

					if (EX)
						m_exp = m_exp * 1.2;
					p.exp += m_exp;

					p.levelup(); //레벨 업 여부

					return 0;
				}
				else { //플레이어 사망
					if (isRevive(p)) {
						m.hp = m.max_hp;
						return -1;
					}
					else {
						return 1;
					}
				}
			}
			else { //플레이어 사망
				if (isRevive(p)) {
					m.hp = m.max_hp;
					return -1;
				}
				else {
					return 1;
				}
			}
		}
	}
	else if (HU) {
		p.hp = p.max_hp;
		p_hp = p.hp;
		if (m_hp - PtoM <= 0) {//플레이어 우승
			p.hp = p_hp;

			if (HR)
				p.healHp(3);

			if (EX)
				m_exp = m_exp * 1.2;
			p.exp += m_exp;

			p.levelup(); //레벨 업 여부

			return 0;
		}
		else {
			m_hp -= PtoM;
			int f = 0;
			while (1) {
				m_hp -= PtoM;
				if (m_hp <= 0)
					break;
				p_hp -= MtoP;
				if (p_hp <= 0) {
					f = 1;
					break;
				}
			}
			if (!f) {
				p.hp = p_hp;

				if (HR)
					p.healHp(3);

				if (EX)
					m_exp = m_exp * 1.2;
				p.exp += m_exp;

				p.levelup(); //레벨 업 여부

				return 0;
			}
			else { //플레이어 사망
				if (isRevive(p)) {
					m.hp = m.max_hp;
					return -1;
				}
				else {
					return 1;
				}
			}
		}
	}
	else { //효과 1도없음
		int f = 0;
		while (1) {
			m_hp -= PtoM;
			if (m_hp <= 0)
				break;
			p_hp -= MtoP;
			if (p_hp <= 0) {
				f = 1;
				break;
			}
		}
		if (!f) {
			p.hp = p_hp;

			if (HR)
				p.healHp(3);

			if (EX)
				m_exp = m_exp * 1.2;
			p.exp += m_exp;

			p.levelup(); //레벨 업 여부

			return 0;
		}
		else { //플레이어 사망
			if (isRevive(p)) {
				m.hp = m.max_hp;
				return -1;
			}
			else {
				return 1;
			}
		}
	}
}

int main(void) {
	fastio();
	int N, M;
	cin >> N >> M;
	int monster_cnt = 0, item_cnt = 0;
	int px, py;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == '@') {
				px = i, py = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'M' || arr[i][j] == '&')
				monster_cnt++;
			else if (arr[i][j] == 'B')
				item_cnt++;
		}
	}
	string order;
	cin >> order;

	player P = player(px, py);

	map<pair<int, int>, int>mon_map;
	vector<monster>mon;

	for (int i = 0; i < monster_cnt; i++) {
		int R, C, W,A,H,E;
		string S;
		cin >> R >> C >> S >> W >> A >> H >> E;
		monster MON = monster(R - 1, C - 1, S, W, A, H, E);
		mon.push_back(MON);
		mon_map.insert({ {R - 1,C - 1},i });
	}

	map<pair<int, int>, int> item_map;
	vector<itembox>items;

	for (int i = 0; i < item_cnt; i++) {
		int R, C;
		char T;
		cin >> R >> C >> T;
		itembox it;
		if (T == 'O') {
			string effect;
			cin >> effect;
			it = itembox(R - 1, C - 1, T, effect);
		}
		else {
			int num;
			cin >> num;
			it = itembox(R - 1, C - 1, T, num);
		}
		items.push_back(it);
		item_map.insert({ {R - 1,C - 1},i });
	}

	int turns = 0;
	int flag = 0; //flag 0 그냥 끝남, flag 1 trap 밟고 사망, flag 2 몬스터한테 사망, flag 3 boss킬 우승, flag 4 보스한테 죽음
	int len = order.length();
	string modname; // 플레이어 죽인 몬스터 이름 저장

	for (int i = 0; i < len; i++) {
		int x = P.curX, y = P.curY;
		int tx, ty;
		if (order[i] == 'U') {
			tx = x + xx[0], ty = y + yy[0];
		}
		else if (order[i] == 'R') {
			tx = x + xx[1], ty = y + yy[1];
		}
		else if (order[i] == 'D') {
			tx = x + xx[2], ty = y + yy[2];
		}
		else {
			tx = x + xx[3], ty = y + yy[3];
		}
		if (tx >= 0 && tx < N && ty >= 0 && ty < M && arr[tx][ty] != '#') {
			if (arr[tx][ty] == '.') { // 빈칸
				P.curX = tx, P.curY = ty;
			}
			else if (arr[tx][ty] == '^') { //덫
				bool DX = P.hasEffecf("DX");
				if (DX) {
					P.hp -= 1;
					if (P.hp > 0) {
						P.curX = tx, P.curY = ty;
					}
					else {
						if (!isRevive(P)) {
							flag = 1;
							P.hp = 0;
						}
					}
				}
				else {
					P.hp -= 5;
					if (P.hp > 0) {
						P.curX = tx, P.curY = ty;
					}
					else {
						if(!isRevive(P)) {
							flag = 1;
							P.hp = 0;
						}

					}
				}
			}
			else if (arr[tx][ty] == 'B') { //아이템 상자
				itembox item = items[item_map[{tx, ty}]];
				getItemBox(P, item);
				arr[tx][ty] = '.';
				P.curX = tx, P.curY = ty;
			}
			else if (arr[tx][ty] == '&') {
				monster MON = mon[mon_map[{tx, ty}]];
				int fightResult = fightWithMonster(P, MON);
				if (!fightResult) {
					arr[tx][ty] = '.';
					P.curX = tx, P.curY=ty;
				}
				else if (fightResult == 1) { //플레이어 사망
					flag = 2;
					modname = MON.name;
				}
			}
			else { // 보스
				monster BOSS = mon[mon_map[{tx, ty}]];
				int fightResult = fightWithBoss(P, BOSS);
				if (!fightResult) {
					arr[tx][ty] = '.';
					P.curX = tx, P.curY = ty;
					flag = 3;
				}
				else if (fightResult == 1) {
					flag = 4;
					modname = BOSS.name;
				}
			}
		}
		else { //막히거나 못가는 곳
			tx = x, ty = y;
			if (arr[tx][ty] == '^') {
				bool DX = P.hasEffecf("DX");
				if (DX) {
					P.hp -= 1;
					if (P.hp > 0) {
						P.curX = tx, P.curY = ty;
					}
					else {
						if (!isRevive(P)) {
							flag = 1;
							P.hp = 0;
						}
					}
				}
				else {
					P.hp -= 5;
					if (P.hp > 0) {
						P.curX = tx, P.curY = ty;
					}
					else {
						if (!isRevive(P)) {
							flag = 1;
							P.hp = 0;
						}

					}
				}
			}
		}
		turns++;
		if (flag)
			break;
	}

	if (flag == 0 || flag == 3) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (P.curX == i && P.curY == j)
					cout << '@';
				else
					cout << arr[i][j];
			}
			cout << '\n';
		}
		cout << "Passed Turns : " << turns << '\n';
		cout << "LV : " << P.lev << '\n';
		cout << "HP : " << P.hp << '/' << P.max_hp << '\n';
		cout << "ATT : " << P.atk << '+' << P.weapon << '\n';
		cout << "DEF : " << P.def << '+' << P.armor << '\n';
		cout << "EXP : " << P.exp << '/' << P.lev * 5 << '\n';
		if (flag == 3)
			cout << "YOU WIN!" << '\n';
		else
			cout << "Press any key to continue." << '\n';
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
					cout << arr[i][j];
			}
			cout << '\n';
		}
		cout << "Passed Turns : " << turns << '\n';
		cout << "LV : " << P.lev << '\n';
		cout << "HP : " << P.hp << '/' << P.max_hp << '\n';
		cout << "ATT : " << P.atk << '+' << P.weapon << '\n';
		cout << "DEF : " << P.def << '+' << P.armor << '\n';
		cout << "EXP : " << P.exp << '/' << P.lev * 5 << '\n';
		if (flag == 1)
			cout << "YOU HAVE BEEN KILLED BY SPIKE TRAP.." << '\n';
		else
			cout << "YOU HAVE BEEN KILLED BY " << modname << ".." << '\n';
	}
	return 0;
}