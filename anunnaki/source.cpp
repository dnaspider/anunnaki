#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <chrono>
#include <regex>
#include <codecvt>
#include <thread>

using namespace std;

struct Strand
{
	//unsigned int line{};
	wstring out{};
	wstring in{};
	wstring g{};
};

#pragma region globals
wstring&& Kb_Key_A = L"a", Kb_Key_B = L"b", Kb_Key_C = L"c", Kb_Key_D = L"d", Kb_Key_E = L"e", Kb_Key_F = L"f", Kb_Key_G = L"g", Kb_Key_H = L"h", Kb_Key_I = L"i", Kb_Key_J = L"j", Kb_Key_K = L"k", Kb_Key_L = L"l", Kb_Key_M = L"m", Kb_Key_N = L"n", Kb_Key_O = L"o", Kb_Key_P = L"p", Kb_Key_Q = L"q", Kb_Key_R = L"r", Kb_Key_S = L"s", Kb_Key_T = L"t", Kb_Key_U = L"u", Kb_Key_V = L"v", Kb_Key_W = L"w", Kb_Key_X = L"x", Kb_Key_Y = L"y", Kb_Key_Z = L"z",
Kb_Key_0 = L"0", Kb_Key_1 = L"1", Kb_Key_2 = L"2", Kb_Key_3 = L"3", Kb_Key_4 = L"4", Kb_Key_5 = L"5", Kb_Key_6 = L"6", Kb_Key_7 = L"7", Kb_Key_8 = L"8", Kb_Key_9 = L"9",
Kb_Key_F1 = L"", Kb_Key_F2 = L">", Kb_Key_F3 = L"", Kb_Key_F4 = L"", Kb_Key_F5 = L"", Kb_Key_F6 = L"", Kb_Key_F7 = L"", Kb_Key_F8 = L"", Kb_Key_F9 = L"", Kb_Key_F10 = L"", Kb_Key_F11 = L"", Kb_Key_F12 = L"",
Kb_Key_Left = L"", Kb_Key_Up = L"", Kb_Key_Right = L"", Kb_Key_Down = L"",
Kb_Key_Esc = L"", Kb_Key_Space = L"", Kb_Key_Tab = L"", Kb_Key_Left_Shift = L"", Kb_Key_Right_Shift = L"", Kb_Key_Left_Alt = L"", Kb_Key_Right_Alt = L"", Kb_Key_Left_Ctrl = L"", Kb_Key_Right_Ctrl = L"", Kb_Key_Enter = L"", Kb_Key_Caps = L"", Kb_Key_Grave_Accent = L"", Kb_Key_Minus = L"", Kb_Key_Equal = L"", Kb_Key_Left_Bracket = L"", Kb_Key_Right_Bracket = L"", Kb_Key_Backslash = L"", Kb_Key_Semicolon = L"", Kb_Key_Quote = L"", Kb_Key_Comma = L"", Kb_Key_Period = L"", Kb_Key_Forwardslash = L"", Kb_Key_Menu = L"",
Kb_Key_Print_Screen = L"", Kb_Key_Insert = L"", Kb_Key_Delete = L"", Kb_Key_Home = L"", Kb_Key_End = L"", Kb_Key_PgUp = L"", Kb_Key_PgDn = L"",
Kb_Key_Numpad_0 = L"", Kb_Key_Numpad_1 = L"", Kb_Key_Numpad_2 = L"", Kb_Key_Numpad_3 = L"", Kb_Key_Numpad_4 = L"", Kb_Key_Numpad_5 = L"", Kb_Key_Numpad_6 = L"", Kb_Key_Numpad_7 = L"", Kb_Key_Numpad_8 = L"", Kb_Key_Numpad_9 = L"", Kb_Key_Numlock = L"", Kb_Key_Numpad_Divide = L"", Kb_Key_Numpad_Multiply = L"", Kb_Key_Numpad_Minus = L"", Kb_Key_Numpad_Add = L"", Kb_Key_Numpad_Period = L"", Kb_Key_Numpad_Enter = L""
;
wstring database = L"c:\\anu\\db.txt",
settings = L"c:\\anu\\se.txt",
replacerDb = L"";
wstring&& editor = L"Visual Studio Code",
db = L"db.txt - ", se = L"se.txt - ",
editorSe = se + editor, editorDb = db + editor;
wstring strand = L"";
wstring qq = L"", qp = L"", qx = L"", qy = L"";
wstring repeats = L"";
wstring Loop_Insert_Text = L"";
wstring out = L"", in = L"";
wstring w_delimiter = L"\n"; //°";
string delimiter = ""; //°";
double RgbScaleLayout = 1.00; //100%
double ic = 0; //<+> icp
vector<Strand> vstrand{};
size_t c = 0;
int qxcc = 0, qycc = 0;
unsigned short out_speed = 0;
unsigned short frequency = 160;
unsigned short strand_length = 2;
unsigned short RSHIFTLSHIFT_Only = 0, rri = 0;
unsigned short cKey = VK_RCONTROL, cKeyMax = 9;
unsigned short repeat_key = VK_PAUSE;
unsigned short PauseKey = VK_F12; //123
unsigned short clear_strand_key = 0; //VK_F12;
unsigned short RSHIFTCtrlKeyToggle = 9;
unsigned short LSHIFTCtrlKey = 9;
unsigned short repeat_switch = 0;
unsigned short debug = 0;
unsigned short mvdb = 0; //make vstrand to vdb
bool start_hidden = 0;
bool show_strand = 1;
bool ignoreAZ = 0;
bool ignore09 = 0;
bool ignoreF1s = 0; //f1-f12
bool ignoreArrows = 1;
bool ignoreNumPad = 1;
bool ignoreOtherKeys = 1;
bool auto_bs_repeat_key = 0;
bool ctrl_scan_only_mode = 0;
bool close_ctrl_mode = 1;
bool ManualRepeat = 1;
bool hold_shift = 0;
bool out_sleep = 1;
bool stop = 0;
bool utf_8 = 1;
bool ccm = 0; //close_ctrl_mode toggle

#pragma endregion

struct Multi_ {
	wstring out_,
		qq_ = qq,
		qp_ = qp,
		strand_ = strand,
		store_ = L"";
	double
		icp_ = 0;
	size_t
		c_ = c;
	bool
		br_ = 0;
};

#pragma region protos
static void showOutsMsg(wstring, wstring, wstring, bool),
	run(wstring, vector<Strand> const&, bool),
	scan_db(vector<Strand> const&, bool),
	repeat(vector<Strand> const&),
	clear_all_keys()
;

#pragma endregion

#pragma region subs
static std::wstring utf8_to_wstring(const std::string& str) {
	if (str.empty()) return {};
	int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
	if (size_needed == 0) return {};
	std::wstring wstr(size_needed - 1, L'\0');
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], size_needed);
	return wstr;
}

static std::string wstring_to_utf8(const std::wstring& wstr) {
	if (wstr.empty()) return {};
	int size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
	if (size_needed == 0) return {};
	std::string str(size_needed - 1, '\0');
	WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], size_needed, nullptr, nullptr);
	return str;
}

static vector<Strand> make_vdb_table() {
	ifstream f(database);

	if (!f) { showOutsMsg(L"", L"\\0C\\" + database + L"\\0C\\\\4 not found!\\7\\n", L"", 1); return vstrand; }

	f.imbue(locale("en_us.utf8")); //extract

	wstring cell;
	string cells;

	//unsigned int line{};
	vstrand.push_back({ L"", L"", L"" }); //connect

	while (getline(f, cells, delimiter[0])) {

		cell = utf8_to_wstring(cells);

		if (delimiter[0] != '\n')
			if (delimiter[0] > 127)
				cell = cell.substr(0, cell.length() - 1);

		Strand s{};

		//s.line = line;

		if (cell[0]) {
			if (cell.substr(0, 4) == L"<'''")
				break;

			s.in = cell.substr(0, cell.find_first_of(L" -:>"));

			if (!s.g[0]) {
				s.g = cell.substr(s.in.length(), 1);
				if (s.g[0] && s.g[0] != '>') s.g += cell[s.in.length() + 1] == '>' ? L">" : L"";
			}

			s.out = cell.substr(s.in.length() + s.g.length());

			if (s.in[0] == '<')
				s.in += s.g;
		}

		vstrand.push_back(s);

		//++line;

	}
	f.close();

	return vstrand;
}

static wstring getTime(wstring& w) {
	auto np = chrono::system_clock::now();
	auto n = chrono::system_clock::to_time_t(np);
	char b[26];
	ctime_s(b, sizeof(b), &n);
	for (auto i = 0; i < 26; ++i) {
		if (b[i] == '\n') break;
		w += b[i];
	}
	return w;
}

static void cbSet(wstring& s) {
	auto length = 2 * (wcslen(s.c_str()) + 1);
	HGLOBAL h = GlobalAlloc(GMEM_DDESHARE, length);
	if (h != NULL) {
		auto x = GlobalLock(h);
		if (x != NULL) memcpy(x, s.c_str(), length);
		GlobalUnlock(h);
		OpenClipboard(0);
		EmptyClipboard();
		SetClipboardData(CF_UNICODETEXT, h);
		CloseClipboard();
	}
}

static auto cbGet(wstring cb = L"") {
	OpenClipboard(0);
	HANDLE b = GetClipboardData(CF_UNICODETEXT);
	if (b != nullptr) {
		wchar_t* t = static_cast<wchar_t*>(GlobalLock(b));
		if (t != nullptr) cb = t;
		GlobalUnlock(b);
	}
	CloseClipboard();
	return cb;
}

static void num_error(wstring error_msg = L"", wstring v = L"", wstring nan = L"NAN:") {
	wstring e = error_msg[0] ? L" " : L"";
	e += L"\\4";
	e += nan;
	e += L" \\7{\\4\\0C\\" + v + L"\\0C\\\\7}\\n";
	showOutsMsg(error_msg, e, L"", 1);
	c = out.length();
	ShowWindow(GetConsoleWindow(), SW_RESTORE);
	SetForegroundWindow(GetConsoleWindow());
}

static wstring check_if_num(wstring& s, wstring error_msg = L"") {
	if (debug == 2) return s;

	char d = 0;

	for (size_t x = 0; x < s.length(); ++x) {
		if (x == 0 && s[0] == '-') { if (s.length() == 1) { num_error(error_msg, s); s.clear(); break; } continue; }
		if (s[x] == '.') { ++d; if (d > 1 || s.length() == 1) { num_error(error_msg, s); s.clear(); break; } continue; }
		if (s[x] < '0' || s[x] > '9') { num_error(error_msg, s); s.clear(); break; }
	}

	return s;
}

static void kb(wchar_t b) { //out char
	INPUT ip[2]{}; ip[0].type = INPUT_KEYBOARD;
	ip[0].ki.dwFlags = KEYEVENTF_UNICODE;
	if (VkKeyScanW(b) == -1) { ip[0].ki.wScan = b; ip[0].ki.wVk = 0; }
	else { ip[0].ki.wVk = VkKeyScanW(b); }
	ip[1] = ip[0]; ip[1].ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(2, ip, sizeof(ip[0]));
}

static void showOutsMsg(wstring s, wstring w, wstring s1 = L"", bool make_color = 1) {
	HANDLE hC = GetStdHandle(STD_OUTPUT_HANDLE);
	size_t x = 0; bool t = 0;
	if (delimiter[0] != '\n') { w = regex_replace(w, wregex(L"\n"), L""); w = regex_replace(w, wregex(L"\t"), L""); }
	auto write = [&x, &t](wstring w) {
		wcout << w;
		++x; t = 1;
		};
	auto color = [&x, &t, &w, hC, &make_color](WORD n) {
		if (make_color) SetConsoleTextAttribute(hC, n);
		if (!make_color) wcout << w.substr(x, 2);
		++x; t = 1;
		if (w[x] == '\\') --x;
		};
	if (s[0]) wcout << s;
	if (utf_8) { kb(VK_ESCAPE); GetAsyncKeyState(VK_ESCAPE); } //hack
	for (; x < w.length(); ++x) {
		if (w[x] == '\\') {
			t = 0;
			switch (w[x + 1]) {
			case'+':
			{ if (make_color) { write(to_wstring(ic)); ++ic; } } break; //<+>
			case'a':
			{ if (make_color) write(L"\a"); } break; //beep
			case'0': { /* \012\ */
				wstring n = w.substr(x + 2);
				n = n.substr(0, n.find(L"\\"));
				w = w.substr(x + n.length() + 3);
				x = -1;
				if (n == L"C") { make_color = !make_color; t = 1; break; } /* \0C\ toggle make_color */
				if (make_color && check_if_num(n) == L"" || n == L"0") { t = 1; break; }
				if (make_color) SetConsoleTextAttribute(hC, stoi(n));
				else wcout << L"\\0" << n << "\\";
				t = 1; break;
			}
			case'1':
			case'B':
				color(1); break; //blu
			case'2':
			case'G':
				color(2); break; //gr
			case'3':
				color(3); break;
			case'4':
			case'R':
				color(4); break; //r
			case'5':
				color(5); break;
			case'6':
				color(6); break;
			case'7':
			case'W':
				color(7); break; //white
			case'8':
				color(8); break;
			case'9':
				color(9); break;
			case '\\':
			{ if (make_color) write(L"\\"); }
			break;
			case '\'':
				if (make_color) {
					x = w.length() - 1;
					t = 1;
				}
				break;
			case 'c':
			{ if (make_color) write(cbGet()); }
			break;
			case 'm':
			{ if (make_color) write(utf8_to_wstring(delimiter)); }
			break;
			case 'n':
			{ if (make_color) write(L"\n"); }
			break;
			case 'T':
			{ if (make_color) { wstring w{}; getTime(w); write(w); } }
			break;
			case 't':
			{ if (make_color) write(L"\t"); }
			break;
			case 'g':
			{ if (make_color) write(L">"); }
			break;
			}
			if (t) continue;
		}
		if (w[x] < 128) wcout << w[x];
		else { wcout << w.substr(x, 2); ++x; }
	}
	if (s1[0]) wcout << s1;
}

static void load_settings() {
	ifstream f(settings);
	f.imbue(locale("en_US.utf8"));

	if (!f) {
		showOutsMsg(L"", L"\\n\\4Settings \\7\\0C\\" + settings + L"\\0C\\\\4 not found!\\7\\n", L"", 1);
		if (!settings[0]) { cout << "Create c:\\anu\\se.txt manually\n"; }
		return;
	}

	wstring cell; string cells; while (getline(f, cells)) {
		cell = utf8_to_wstring(cells);
		if (!cell[0] || cell[0] == ' ') continue;
		wstring se = cell.substr(0, cell.find_first_of(L":\t ")); se += ':';
		wstring v = (cell.substr(cell.find_first_of(L":\t ") + 1)); if (v.find_first_not_of(L"\t ") == string::npos) {//""
			if (v != L" ") v.clear();
		} if (se == cell + L":") v.clear();
		if (v[0] && v != L" ") v = v.substr(v.find_first_not_of(L"\t "));
		int x = 0; for (size_t i = 0; i <= se.length(); ++i) x += se[i];

		auto er = [se, v]() { showOutsMsg(L"", L"\\4Error\\7 in \\0C\\" + settings + L"\\0C\\ \\4[" + se + L" " + v + L"]\\7\\n", L"", 1); ShowWindow(GetConsoleWindow(), SW_RESTORE); SetForegroundWindow(GetConsoleWindow()); };
		switch (x) {
		case 545://Debug:
		{ if (v == L"0" || v == L"1" || v == L"2") debug = stoi(v); else er(); } break;
		case 353://UTF8:
		{ if (se == L"UTF8:") { if (v == L"0" || v == L"1") if (v == L"1" && !utf_8) { wcout.flush().clear(); num_error(L"Reload program for", L"1", L"UTF_8:"); } utf_8 = stoi(v); } else er(); } break;
		case 1536://RSHIFT+LSHIFT_Only:
		{ if (check_if_num(v) > L"") { RSHIFTLSHIFT_Only = stoi(v); rri = 0; } else er(); } break;
		case 1261://LSHIFT+CtrlKey:
		{ if (check_if_num(v) > L"") LSHIFTCtrlKey = stoi(v); else er(); } break;
		case 1972://RSHIFT+CtrlKey_Toggle:
		{ if (check_if_num(v) > L"") RSHIFTCtrlKeyToggle = stoi(v); else er(); } break;
		case 1273://ManualRepeat:
		{ if (v == L"0" || v == L"1") ManualRepeat = stoi(v); else er(); } break;
		case 865://PauseKey:
		{ if (check_if_num(v) > L"") PauseKey = stoi(v); else er(); } break;
		case 1708://Loop_Insert_Text:
		{ if (!v[0]) { v[0] = '>'; } if (v[v.length() - 1] != '>') v += '>'; Loop_Insert_Text = v; } break;
		case 1946://Kb_Key_Print_Screen:
			Kb_Key_Print_Screen = v; break;
		case 783://Kb_Key_A:
			Kb_Key_A = v; break;
		case 784://Kb_Key_B:
			Kb_Key_B = v; break;
		case 785://Kb_Key_C:
			Kb_Key_C = v; break;
		case 786://Kb_Key_D:
			Kb_Key_D = v; break;
		case 787://Kb_Key_E:
			Kb_Key_E = v; break;
		case 788://Kb_Key_F:
			Kb_Key_F = v; break;
		case 789://Kb_Key_G:
			Kb_Key_G = v; break;
		case 790://Kb_Key_H:
			Kb_Key_H = v; break;
		case 791://Kb_Key_I:
			Kb_Key_I = v; break;
		case 792://Kb_Key_J:
			Kb_Key_J = v; break;
		case 793://Kb_Key_K:
			Kb_Key_K = v; break;
		case 794://Kb_Key_L:
			Kb_Key_L = v; break;
		case 795://Kb_Key_M:
			Kb_Key_M = v; break;
		case 796://Kb_Key_N:
			Kb_Key_N = v; break;
		case 797://Kb_Key_O:
			Kb_Key_O = v; break;
		case 798://Kb_Key_P:
			Kb_Key_P = v; break;
		case 799://Kb_Key_Q:
			Kb_Key_Q = v; break;
		case 800://Kb_Key_R:
			Kb_Key_R = v; break;
		case 801://Kb_Key_S:
			Kb_Key_S = v; break;
		case 802://Kb_Key_T:
			Kb_Key_T = v; break;
		case 803://Kb_Key_U:
			Kb_Key_U = v; break;
		case 804://Kb_Key_V:
			Kb_Key_V = v; break;
		case 805://Kb_Key_W:
			Kb_Key_W = v; break;
		case 806://Kb_Key_X:
			Kb_Key_X = v; break;
		case 807://Kb_Key_Y:
			Kb_Key_Y = v; break;
		case 808://Kb_Key_Z:
			Kb_Key_Z = v; break;
		case 766://Kb_Key_0:
			Kb_Key_0 = v; break;
		case 767://Kb_Key_1:
			Kb_Key_1 = v; break;
		case 768://Kb_Key_2:
			Kb_Key_2 = v; break;
		case 769://Kb_Key_3:
			Kb_Key_3 = v; break;
		case 770://Kb_Key_4:
			Kb_Key_4 = v; break;
		case 771://Kb_Key_5:
			Kb_Key_5 = v; break;
		case 772://Kb_Key_6:
			Kb_Key_6 = v; break;
		case 773://Kb_Key_7:
			Kb_Key_7 = v; break;
		case 774://Kb_Key_8:
			Kb_Key_8 = v; break;
		case 775://Kb_Key_9:
			Kb_Key_9 = v; break;
		case 837://Kb_Key_F1:
			Kb_Key_F1 = v; break;
		case 838://Kb_Key_F2:
			Kb_Key_F2 = v; break;
		case 839://Kb_Key_F3:, EditorDb:
		{
			if (se == L"EditorDb:") editorDb = v;
			else if (se == L"Kb_Key_F3:") Kb_Key_F3 = v;
		} break;
		case 840://Kb_Key_F4:
			Kb_Key_F4 = v; break;
		case 841://Kb_Key_F5:
			Kb_Key_F5 = v; break;
		case 842://Kb_Key_F6:
			Kb_Key_F6 = v; break;
		case 843://Kb_Key_F7:
			Kb_Key_F7 = v; break;
		case 844://Kb_Key_F8:
			Kb_Key_F8 = v; break;
		case 845://Kb_Key_F9:
			Kb_Key_F9 = v; break;
		case 885://Kb_Key_F10:
			Kb_Key_F10 = v; break;
		case 886://Kb_Key_F11:
			Kb_Key_F11 = v; break;
		case 887://Kb_Key_F12:
			Kb_Key_F12 = v; break;
		case 1113://Kb_Key_Left:
			Kb_Key_Left = v; break;
		case 1126://Kb_Key_Down:
			Kb_Key_Down = v; break;
		case 1210://Kb_Key_Space:
			Kb_Key_Space = v; break;
		case 1718://Kb_Key_Left_Shift:
			Kb_Key_Left_Shift = v; break;
		case 1833://Kb_Key_Right_Shift:
			Kb_Key_Right_Shift = v; break;
		case 1497://Kb_Key_Left_Alt:
			Kb_Key_Left_Alt = v; break;
		case 1612://Kb_Key_Right_Alt:
			Kb_Key_Right_Alt = v; break;
		case 1613://Kb_Key_Left_Ctrl:
			Kb_Key_Left_Ctrl = v; break;
		case 1728://Kb_Key_Right_Ctrl:
			Kb_Key_Right_Ctrl = v; break;
		case 1228://Kb_Key_Enter: | Kb_Key_Right:
		{
			if (se == L"Kb_Key_Enter:") Kb_Key_Enter = v;
			else if (se == L"Kb_Key_Right:") Kb_Key_Right = v;
		} break;
		case 1109://Kb_Key_Caps:
			Kb_Key_Caps = v; break;
		case 1904://Kb_Key_Grave_Accent:
			Kb_Key_Grave_Accent = v; break;
		case 1242://Kb_Key_Minus:
			Kb_Key_Minus = v; break;
		case 1222://Kb_Key_Equal:
			Kb_Key_Equal = v; break;
		case 1908://Kb_Key_Left_Bracket:
			Kb_Key_Left_Bracket = v; break;
		case 1626://Kb_Key_Backslash:
			Kb_Key_Backslash = v; break;
		case 1655://Kb_Key_Semicolon:
			Kb_Key_Semicolon = v; break;
		case 1244://Kb_Key_Quote:
			Kb_Key_Quote = v; break;
		case 1211://Kb_Key_Comma:
			Kb_Key_Comma = v; break;
		case 1329://Kb_Key_Period:
			Kb_Key_Period = v; break;
		case 1982://Kb_Key_Forwardslash:
			Kb_Key_Forwardslash = v; break;
		case 1123://Kb_Key_Menu:
			Kb_Key_Menu = v; break;
		case 1347://Kb_Key_Insert:
			Kb_Key_Insert = v; break;
		case 1111://Kb_Key_Home:
			Kb_Key_Home = v; break;
		case 997://Kb_Key_End: | Kb_Key_Tab:
		{
			if (se == L"Kb_Key_End:") Kb_Key_End = v;
			else if (se == L"Kb_Key_Tab:") Kb_Key_Tab = v;
		} break;
		case 1079://Kb_Key_PgDn:
			Kb_Key_PgDn = v; break;
		case 1474://Kb_Key_Numpad_0:
			Kb_Key_Numpad_0 = v; break;
		case 1475://Kb_Key_Numpad_1:
			Kb_Key_Numpad_1 = v; break;
		case 1476://Kb_Key_Numpad_2:
			Kb_Key_Numpad_2 = v; break;
		case 1477://Kb_Key_Numpad_3:
			Kb_Key_Numpad_3 = v; break;
		case 1478://Kb_Key_Numpad_4:
			Kb_Key_Numpad_4 = v; break;
		case 1479://Kb_Key_Numpad_5:
			Kb_Key_Numpad_5 = v; break;
		case 1480://Kb_Key_Numpad_6:
			Kb_Key_Numpad_6 = v; break;
		case 1481://Kb_Key_Numpad_7:
			Kb_Key_Numpad_7 = v; break;
		case 1482://Kb_Key_Numpad_8:
			Kb_Key_Numpad_8 = v; break;
		case 1483://Kb_Key_Numpad_9:
			Kb_Key_Numpad_9 = v; break;
		case 1447://Kb_Key_Numlock:
			Kb_Key_Numlock = v; break;
		case 2023://Kb_Key_Numpad_Divide: | Kb_Key_Right_Bracket:
		{
			if (se == L"Kb_Key_Numpad_Divide:") Kb_Key_Numpad_Divide = v;
			else if (se == L"Kb_Key_Right_Bracket:") Kb_Key_Right_Bracket = v;
		} break;
		case 2290://Kb_Key_Numpad_Multiply:
			Kb_Key_Numpad_Multiply = v; break;
		case 1950://Kb_Key_Numpad_Minus:
			Kb_Key_Numpad_Minus = v; break;
		case 1691://Kb_Key_Numpad_Add:
			Kb_Key_Numpad_Add = v; break;
		case 2037://Kb_Key_Numpad_Period:
			Kb_Key_Numpad_Period = v; break;
		case 1936://Kb_Key_Numpad_Enter:
			Kb_Key_Numpad_Enter = v; break;
		case 2066://DbMultiLineDelimiter:
			delimiter = wstring_to_utf8(v);
			if (delimiter[0] != '\n')
				delimiter = delimiter.substr(1);
			break;
		case 1370://ClearInputKey:
		{ if (check_if_num(v) > L"") clear_strand_key = stoi(v); else er(); } break;
		case 673://Editor:
			editor = v; break;
		case 857://EditorSe:
			editorSe = v; break;
		case 1003://ShowInput:
		{ if (v == L"0" || v == L"1") show_strand = stoi(v); else er(); } break;
		case 847://Database:
		{ if (v.length() > 0) { database = v; database = regex_replace(database, wregex(L"/"), L"\\"); db = database.substr(database.find_last_of('\\') + 1) + L" - "; } else er(); } break;
		case 907://Settings:
		{ if (v.length() > 0) { settings = v; settings = regex_replace(settings, wregex(L"/"), L"\\"); se = settings.substr(settings.find_last_of('\\') + 1) + L" - "; } else er(); } break;
		case 1038://ReplacerDb:
			replacerDb = v; break;
		case 1313://Kb_Key_Delete:
			if (se == L"Kb_Key_Delete:") Kb_Key_Delete = v; break;
		case 1354://CloseCtrlMode:
		{ if (v == L"0" || v == L"1") close_ctrl_mode = stoi(v); else er(); } break;
		case 1659://CtrlScanOnlyMode:
		{ if (v == L"0" || v == L"1") ctrl_scan_only_mode = stoi(v); else er(); } break;
		case 1196://InputLength:
		{ if (check_if_num(v) > L"") strand_length = stoi(v); else er(); } break;
		case 965://Ignore_A-Z:
		{ if (v == L"0" || v == L"1") ignoreAZ = stoi(v); else er(); } break;
		case 915://Ignore_0-9: | Kb_Key_Up:
		{
			if (se == L"Ignore_0-9:") { if (v == L"0" || v == L"1") ignore09 = stoi(v); else er(); }
			else if (se == L"Kb_Key_Up:")Kb_Key_Up = v;
		} break;
		case 1172://StartHidden:
		{ if (v == L"0" || v == L"1") start_hidden = stoi(v); else er(); } break;
		case 760://CtrlKey: (vk_enum max)
		{
			if (v.find(' ') != string::npos) {
				wstring max = v.substr(v.find(' ') + 1); if (max.find(' ') != string::npos || max[0] == 0) { er(); break; }
				v = v.substr(0, v.find(' '));
				if (check_if_num(max, L"CtrlKey duration") == L"") { er(); break; }
				cKeyMax = max == L"1" ? 3 : stoi(max);
			}
			else cKeyMax = 1;
			if (check_if_num(v, L"CtrlKey") == L"") { er(); break; }
			cKey = stoi(v);
		} break;
		case 1004://Frequency:
		{ if (check_if_num(v) > L"") frequency = stoi(v); else er(); } break;
		case 964://RepeatKey:
		{ if (check_if_num(v) > L"") repeat_key = stoi(v); else er(); } break;
		case 1649://AutoBs_RepeatKey:
		{ if (v == L"0" || v == L"1") auto_bs_repeat_key = stoi(v); else er(); } break;
		case 1467://RgbScaleLayout:
		{ if (check_if_num(v) > L"") RgbScaleLayout = stod(v); else er(); } break;
		case 1098://Ignore_F1-F12: | Kb_Key_PgUp:
		{
			if (se == L"Ignore_F1-F12:") { if (v == L"0" || v == L"1") ignoreF1s = stoi(v); else er(); }
			else if (se == L"Kb_Key_PgUp:") Kb_Key_PgUp = v;
		} break;
		case 1403://Ignore_Arrows:
		{ if (v == L"0" || v == L"1") ignoreArrows = stoi(v); else er(); } break;
		case 1001://Kb_Key_Esc:
			Kb_Key_Esc = v; break;
		case 1346://Ignore_NumPad:
		{ if (v == L"0" || v == L"1") ignoreNumPad = stoi(v); else er(); } break;

		}
		if (Kb_Key_Print_Screen[0] || Kb_Key_Space[0] || Kb_Key_Tab[0] || Kb_Key_Left_Shift[0] || Kb_Key_Right_Shift[0] || Kb_Key_Left_Ctrl[0] || Kb_Key_Right_Ctrl[0] || Kb_Key_Enter[0] || Kb_Key_Caps[0] || Kb_Key_Grave_Accent[0] || Kb_Key_Minus[0] || Kb_Key_Equal[0] || Kb_Key_Left_Bracket[0] || Kb_Key_Right_Bracket[0] || Kb_Key_Backslash[0] || Kb_Key_Semicolon[0] || Kb_Key_Quote[0] || Kb_Key_Comma[0] || Kb_Key_Period[0] || Kb_Key_Forwardslash[0] || Kb_Key_Menu[0] || Kb_Key_Insert[0] || Kb_Key_Delete[0] || Kb_Key_Home[0] || Kb_Key_End[0] || Kb_Key_PgUp[0] || Kb_Key_PgDn[0])
			ignoreOtherKeys = 0;
		else
			ignoreOtherKeys = 1;
	}
	f.close();
	clear_all_keys();
}

static void printSe() {
	if (qq[1] == 's') load_settings();
	if (qq[1] == 's' || qq[1] == 'S') {
		if (qq[1] == 'S') return;
		wcout << settings << '\n'; ifstream f(settings); if (f.fail()) { showOutsMsg(L"Copy to ", settings, L"\n", 0); }
		cout << "StartHidden: " << start_hidden << '\n';
		wcout << "Settings: " << settings << '\n';
		wcout << "Database: " << database << '\n';
		cout << "DbMultiLineDelimiter: "; if (delimiter[0] == '\n') cout << "\\n\n"; else cout << delimiter.substr(1) << '\n';
		wcout << "ReplacerDb: " << replacerDb << '\n';
		cout << "UTF8: " << utf_8 << '\n';
		cout << "ShowInput: " << show_strand << '\n';
		cout << "InputLength: " << strand_length << '\n';
		cout << "ClearInputKey: " << clear_strand_key << '\n';
		cout << "CtrlKey: " << cKey << ' ' << cKeyMax << '\n';
		cout << "CloseCtrlMode: " << close_ctrl_mode << '\n';
		cout << "LSHIFT+CtrlKey: " << LSHIFTCtrlKey << '\n';
		cout << "RSHIFT+CtrlKey_Toggle: " << RSHIFTCtrlKeyToggle << '\n';
		cout << "CtrlScanOnlyMode: " << ctrl_scan_only_mode << '\n';
		cout << "RSHIFT+LSHIFT_Only: " << RSHIFTLSHIFT_Only << '\n';
		cout << "RepeatKey: " << repeat_key << '\n';
		cout << "PauseKey: " << PauseKey << '\n';
		cout << "RgbScaleLayout: " << RgbScaleLayout << '\n';
		cout << "Frequency: " << frequency << '\n';
		cout << "Ignore_0-9: " << ignore09 << '\n';
		wcout << "Kb_Key_0: " << Kb_Key_0 << '\n';
		wcout << "Kb_Key_1: " << Kb_Key_1 << '\n';
		wcout << "Kb_Key_2: " << Kb_Key_2 << '\n';
		wcout << "Kb_Key_3: " << Kb_Key_3 << '\n';
		wcout << "Kb_Key_4: " << Kb_Key_4 << '\n';
		wcout << "Kb_Key_5: " << Kb_Key_5 << '\n';
		wcout << "Kb_Key_6: " << Kb_Key_6 << '\n';
		wcout << "Kb_Key_7: " << Kb_Key_7 << '\n';
		wcout << "Kb_Key_8: " << Kb_Key_8 << '\n';
		wcout << "Kb_Key_9: " << Kb_Key_9 << '\n';
		cout << "Ignore_A-Z: " << ignoreAZ << '\n';
		wcout << "Kb_Key_A: " << Kb_Key_A << '\n';
		wcout << "Kb_Key_B: " << Kb_Key_B << '\n';
		wcout << "Kb_Key_C: " << Kb_Key_C << '\n';
		wcout << "Kb_Key_D: " << Kb_Key_D << '\n';
		wcout << "Kb_Key_E: " << Kb_Key_E << '\n';
		wcout << "Kb_Key_F: " << Kb_Key_F << '\n';
		wcout << "Kb_Key_G: " << Kb_Key_G << '\n';
		wcout << "Kb_Key_H: " << Kb_Key_H << '\n';
		wcout << "Kb_Key_I: " << Kb_Key_I << '\n';
		wcout << "Kb_Key_J: " << Kb_Key_J << '\n';
		wcout << "Kb_Key_K: " << Kb_Key_K << '\n';
		wcout << "Kb_Key_L: " << Kb_Key_L << '\n';
		wcout << "Kb_Key_M: " << Kb_Key_M << '\n';
		wcout << "Kb_Key_N: " << Kb_Key_N << '\n';
		wcout << "Kb_Key_O: " << Kb_Key_O << '\n';
		wcout << "Kb_Key_P: " << Kb_Key_P << '\n';
		wcout << "Kb_Key_Q: " << Kb_Key_Q << '\n';
		wcout << "Kb_Key_R: " << Kb_Key_R << '\n';
		wcout << "Kb_Key_S: " << Kb_Key_S << '\n';
		wcout << "Kb_Key_T: " << Kb_Key_T << '\n';
		wcout << "Kb_Key_U: " << Kb_Key_U << '\n';
		wcout << "Kb_Key_V: " << Kb_Key_V << '\n';
		wcout << "Kb_Key_W: " << Kb_Key_W << '\n';
		wcout << "Kb_Key_X: " << Kb_Key_X << '\n';
		wcout << "Kb_Key_Y: " << Kb_Key_Y << '\n';
		wcout << "Kb_Key_Z: " << Kb_Key_Z << '\n';
		cout << "Ignore_Arrows: " << ignoreArrows << '\n';
		wcout << "Kb_Key_Left: " << Kb_Key_Left << '\n';
		wcout << "Kb_Key_Up: " << Kb_Key_Up << '\n';
		wcout << "Kb_Key_Right: " << Kb_Key_Right << '\n';
		wcout << "Kb_Key_Down: " << Kb_Key_Down << '\n';
		wcout << "Kb_Key_Backslash: " << Kb_Key_Backslash << '\n';
		wcout << "Kb_Key_Caps: " << Kb_Key_Caps << '\n';
		wcout << "Kb_Key_Comma: " << Kb_Key_Comma << '\n';
		wcout << "Kb_Key_Delete: " << Kb_Key_Delete << '\n';
		wcout << "Kb_Key_End: " << Kb_Key_End << '\n';
		wcout << "Kb_Key_Enter: " << Kb_Key_Enter << '\n';
		wcout << "Kb_Key_Equal: " << Kb_Key_Equal << '\n';
		wcout << "Kb_Key_Esc: " << Kb_Key_Esc << '\n';
		cout << "Ignore_F1-F12: " << ignoreF1s << '\n';
		wcout << "Kb_Key_F1: " << Kb_Key_F1 << '\n';
		wcout << "Kb_Key_F2: " << Kb_Key_F2 << '\n';
		wcout << "Kb_Key_F3: " << Kb_Key_F3 << '\n';
		wcout << "Kb_Key_F4: " << Kb_Key_F4 << '\n';
		wcout << "Kb_Key_F5: " << Kb_Key_F5 << '\n';
		wcout << "Kb_Key_F6: " << Kb_Key_F6 << '\n';
		wcout << "Kb_Key_F7: " << Kb_Key_F7 << '\n';
		wcout << "Kb_Key_F8: " << Kb_Key_F8 << '\n';
		wcout << "Kb_Key_F9: " << Kb_Key_F9 << '\n';
		wcout << "Kb_Key_F10: " << Kb_Key_F10 << '\n';
		wcout << "Kb_Key_F11: " << Kb_Key_F11 << '\n';
		wcout << "Kb_Key_F12: " << Kb_Key_F12 << '\n';
		wcout << "Kb_Key_Print_Screen: " << Kb_Key_Print_Screen << '\n';
		wcout << "Kb_Key_Forwardslash: " << Kb_Key_Forwardslash << '\n';
		wcout << "Kb_Key_Grave_Accent: " << Kb_Key_Grave_Accent << '\n';
		wcout << "Kb_Key_Home: " << Kb_Key_Home << '\n';
		wcout << "Kb_Key_Insert: " << Kb_Key_Insert << '\n';
		wcout << "Kb_Key_Left_Alt: " << Kb_Key_Left_Alt << '\n';
		wcout << "Kb_Key_Left_Bracket: " << Kb_Key_Left_Bracket << '\n';
		wcout << "Kb_Key_Left_Ctrl: " << Kb_Key_Left_Ctrl << '\n';
		wcout << "Kb_Key_Left_Shift: " << Kb_Key_Left_Shift << '\n';
		wcout << "Kb_Key_Menu: " << Kb_Key_Menu << '\n';
		wcout << "Kb_Key_Minus: " << Kb_Key_Minus << '\n';
		cout << "Ignore_NumPad: " << ignoreNumPad << '\n';
		wcout << "Kb_Key_Numpad_0: " << Kb_Key_Numpad_0 << '\n';
		wcout << "Kb_Key_Numpad_1: " << Kb_Key_Numpad_1 << '\n';
		wcout << "Kb_Key_Numpad_2: " << Kb_Key_Numpad_2 << '\n';
		wcout << "Kb_Key_Numpad_3: " << Kb_Key_Numpad_3 << '\n';
		wcout << "Kb_Key_Numpad_4: " << Kb_Key_Numpad_4 << '\n';
		wcout << "Kb_Key_Numpad_5: " << Kb_Key_Numpad_5 << '\n';
		wcout << "Kb_Key_Numpad_6: " << Kb_Key_Numpad_6 << '\n';
		wcout << "Kb_Key_Numpad_7: " << Kb_Key_Numpad_7 << '\n';
		wcout << "Kb_Key_Numpad_8: " << Kb_Key_Numpad_8 << '\n';
		wcout << "Kb_Key_Numpad_9: " << Kb_Key_Numpad_9 << '\n';
		wcout << "Kb_Key_Numlock: " << Kb_Key_Numlock << '\n';
		wcout << "Kb_Key_Numpad_Divide: " << Kb_Key_Numpad_Divide << '\n';
		wcout << "Kb_Key_Numpad_Multiply: " << Kb_Key_Numpad_Multiply << '\n';
		wcout << "Kb_Key_Numpad_Minus: " << Kb_Key_Numpad_Minus << '\n';
		wcout << "Kb_Key_Numpad_Add: " << Kb_Key_Numpad_Add << '\n';
		wcout << "Kb_Key_Numpad_Period: " << Kb_Key_Numpad_Period << '\n';
		wcout << "Kb_Key_Numpad_Enter: " << Kb_Key_Numpad_Enter << '\n';
		wcout << "Kb_Key_Period: " << Kb_Key_Period << '\n';
		wcout << "Kb_Key_PgDn: " << Kb_Key_PgDn << '\n';
		wcout << "Kb_Key_PgUp: " << Kb_Key_PgUp << '\n';
		wcout << "Kb_Key_Quote: " << Kb_Key_Quote << '\n';
		wcout << "Kb_Key_Right_Alt: " << Kb_Key_Right_Alt << '\n';
		wcout << "Kb_Key_Right_Bracket: " << Kb_Key_Right_Bracket << '\n';
		wcout << "Kb_Key_Right_Ctrl: " << Kb_Key_Right_Ctrl << '\n';
		wcout << "Kb_Key_Right_Shift: " << Kb_Key_Right_Shift << '\n';
		wcout << "Kb_Key_Semicolon: " << Kb_Key_Semicolon << '\n';
		wcout << "Kb_Key_Space: " << Kb_Key_Space << '\n';
		wcout << "Kb_Key_Tab: " << Kb_Key_Tab << '\n';
		cout << "AutoBs_RepeatKey: " << auto_bs_repeat_key << '\n';
		wcout << "Editor: " << editor << '\n';
		wcout << "EditorDb: "; wcout << editorDb << '\n';
		wcout << "EditorSe: "; wcout << editorSe << '\n';
		wcout << "Loop_Insert_Text: " << Loop_Insert_Text << '\n';
		wcout << "ManualRepeat: " << ManualRepeat << '\n';
		cout << endl;
	}
}

static void mouseEvent(short key) {
	INPUT ip{}; ip.type = INPUT_MOUSE; ip.mi.time = 0;
	ip.mi.dwFlags = key;
	if (key == MOUSEEVENTF_HWHEEL) {
		if (qq.substr(0, 3) == L"<sr") ip.mi.mouseData = WHEEL_DELTA;//scroll right
		else if (qq.substr(0, 3) == L"<sd") { ip.mi.dwFlags = MOUSEEVENTF_WHEEL; ip.mi.mouseData = -WHEEL_DELTA; }//scroll down
		else if (qq.substr(0, 3) == L"<sl") ip.mi.mouseData = -WHEEL_DELTA;//scroll left
		else if (qq.substr(0, 3) == L"<su") { ip.mi.dwFlags = MOUSEEVENTF_WHEEL; ip.mi.mouseData = WHEEL_DELTA; }//scroll up
	}
	SendInput(1, &ip, sizeof(ip));
}

static void rei() {
	c += qq.find('>');
}

static void kb_hold(short key) {
	INPUT ip{}; ip.type = INPUT_KEYBOARD; ip.ki.wVk = key; ip.ki.time = 0;
	if (key == VK_LMENU || key == VK_CONTROL) ip.ki.dwFlags = 0; else ip.ki.dwFlags = 1;
	SendInput(1, &ip, sizeof(INPUT));
}

static void kb_release(short key) {
	INPUT ip{}; ip.type = INPUT_KEYBOARD; ip.ki.wVk = key;
	ip.ki.dwFlags = KEYEVENTF_KEYUP; SendInput(1, &ip, sizeof(INPUT));
	GetAsyncKeyState(key);
}

static void shift_release() {
	INPUT ip{}; ip.type = INPUT_KEYBOARD; ip.ki.dwFlags = 2;
	ip.ki.wVk = VK_LSHIFT;
	SendInput(1, &ip, sizeof(INPUT));
	ip.ki.wVk = VK_RSHIFT;
	SendInput(1, &ip, sizeof(INPUT));
	if (hold_shift) hold_shift = false;
	GetAsyncKeyState(VK_LSHIFT);
	GetAsyncKeyState(VK_RSHIFT);
}

static void bs_input(wchar_t k) {
	if (k > 127) return; //exclude non bs: < LURD !@#$%^&*()_+ ~ S H A M C O P
	if (((Kb_Key_Menu[0]) && k == Kb_Key_Menu[0]) ||
		(!ignoreF1s) && (k == Kb_Key_F1[0] || k == Kb_Key_F2[0] || k == Kb_Key_F3[0] || k == Kb_Key_F4[0] || k == Kb_Key_F5[0] || k == Kb_Key_F6[0] || k == Kb_Key_F7[0] || k == Kb_Key_F8[0] || k == Kb_Key_F9[0] || k == Kb_Key_F10[0] || k == Kb_Key_F11[0] || k == Kb_Key_F12[0]) ||
		(Kb_Key_Esc[0] && k == Kb_Key_Esc[0]) ||
		(Kb_Key_Left_Shift[0] && k == Kb_Key_Left_Shift[0]) ||
		(Kb_Key_Right_Shift[0] && k == Kb_Key_Right_Shift[0]) ||
		(Kb_Key_Left_Alt[0] && k == Kb_Key_Left_Alt[0]) ||
		(Kb_Key_Right_Alt[0] && k == Kb_Key_Right_Alt[0]) ||
		(Kb_Key_Left_Ctrl[0] && k == Kb_Key_Left_Ctrl[0]) ||
		(Kb_Key_Right_Ctrl[0] && k == Kb_Key_Right_Ctrl[0]) ||
		(Kb_Key_Caps[0] && k == Kb_Key_Caps[0]))
		return;
	kb(VK_BACK); GetAsyncKeyState(VK_BACK);

}

static void prints() {
	if (show_strand)
		wcout << strand << '\n';
}

static void printq() {
	kb_hold(VK_LSHIFT);
	kb('<');
	shift_release();
}

static void sleep(unsigned short ms) {
	this_thread::sleep_for(chrono::milliseconds(ms));
}

static void kb_press(wstring s, short key) {
	qx = qq.substr(0, qq.find('>', 1) + 1);
	qx = qx.substr(s.length());
	qx = qx.substr(0, qx.length() - (qx[qx.length() - 1] == '>'));
	if (qx[0] == ' ') qx = qx.substr(1);
	if (!qx[0]) qx = L"1";
	if (qx[0] < '0' || qx[0] > '9') { //check_if_num
		printq(); rei(); return;
	}
	unsigned short x = stoi(qx);

	INPUT ip[2]{};
	ip[0].type = INPUT_KEYBOARD;
	ip[0].ki.wVk = key;
	if (key == VK_LEFT || key == VK_UP || key == VK_RIGHT
		|| key == VK_DOWN || key == VK_HOME || key == VK_END)
		ip[0].ki.dwFlags = 1;
	else
		ip[0].ki.dwFlags = 0;
	ip[1] = ip[0];
	ip[1].ki.dwFlags = 2;

	for (int j = 0; j < x; ++j) {
		if (GetAsyncKeyState(VK_ESCAPE))
			return;

		if (s.length() == 3) {
			key = 0;
			if (s == L"<lc") {
				mouseEvent(MOUSEEVENTF_LEFTDOWN);
				mouseEvent(MOUSEEVENTF_LEFTUP);
			}
			else if (s == L"<rc") {
				mouseEvent(MOUSEEVENTF_RIGHTDOWN);
				mouseEvent(MOUSEEVENTF_RIGHTUP);
			}
			else if (s == L"<mc") {
				mouseEvent(MOUSEEVENTF_MIDDLEDOWN);
				mouseEvent(MOUSEEVENTF_MIDDLEUP);
			}
			else if (s == L"<sd" || s == L"<sr"
				|| s == L"<su" || s == L"<sl")
				mouseEvent(MOUSEEVENTF_HWHEEL);
			else
				SendInput(2, ip, sizeof(ip[0]));
		}
		else
			SendInput(2, ip, sizeof(ip[0]));

		GetAsyncKeyState(key);

		if (out_speed > 0 && x != j + 1) sleep(out_speed);
	}

	rei();

}

static bool npos_find(wstring& w, char c, bool b = 1) {
	return b
		? w.find(c) != string::npos
		: w.find(c) == string::npos;
}

static void setQxQy(wstring x, size_t z = 0) {
	if (x.find(',') != string::npos) {
		qx = x.substr(z, x.find(','));//x <xy:#,#>
		qy = x.substr(x.find(',') + 1, x.find('>') - x.find(',') - 1);//y
	}
	else if (npos_find(x, ' ')) {
		qx = x.substr(z, x.find(' '));//x <xy:# #>
		qy = x.substr(x.find(' ') + 1, x.find('>') - x.find(' ') - 1);
	}
	else { qx.clear(), qy.clear(); }
	//wcout << "x: " << x  << "\nqx: " << qx << "\nqy: " << qy << endl;
}

static wstring loadVar(wstring q = L"") {
	ifstream f(replacerDb); if (!f) { showOutsMsg(L"", L"\\n\\4ReplacerDb \\7\\0C\\" + replacerDb + L"\\0C\\\\4 not found!\\7\\n", L"", 1); return q; }
	string cells; wstring cell, se; GetAsyncKeyState(VK_ESCAPE); while (getline(f, cells, delimiter[0])) {
		cell = utf8_to_wstring(cells);
		if (GetAsyncKeyState(VK_ESCAPE) || cell.substr(0, 4) == L"<'''") break;
		if (!cell[0] || cell[0] == '\n' || cell[0] == ' ') continue;
		se = cell.substr(0, q.length());
		if (se == q) {
			wstring v = cell.substr(q.length());
			q = v;
			f.close();
			return q;
		}
	}
	q.clear();
	f.close();
	return q;
}

static wstring isVar(wstring& q) { // Replacer | {var} {var:} {var-} {var>} | <r:>
	if (!replacerDb[0]) return q;
	if (q.find('{') != string::npos) {
		wstring tqg = q, tq{};
		GetAsyncKeyState(VK_ESCAPE);
		while (tqg.find('{') != string::npos) {
			if (GetAsyncKeyState(VK_ESCAPE)) break;
			q = q.substr(q.find('{') + 1, q.find(L'}', q.find('{')) - q.find('{') - 1); tq = q;
			if (q > L"") {
				if (delimiter[0] != '\n') { q = regex_replace(q, wregex(L"\n"), L""); q = regex_replace(q, wregex(L"\t"), L""); }
				if (q[0] == '\'' && q != L"'") { tqg.replace(tqg.find('{'), 2 + q.length(), L""); q = tqg; continue; } //{'ignore}
				q = loadVar(q);
			}
			if (q == L"") {
				tqg.replace(tqg.find('{'), 1, L"::_::"); q = tqg;
				continue;
			}
			q = regex_replace(q, wregex(L"\\$"), L":s:_:s:");
			tq = regex_replace(tq, wregex(L"\\\\"), L":b:_:b:");
			tq = regex_replace(tq, wregex(L"\\$"), L"\\$");
			tq = regex_replace(tq, wregex(L"\\["), L"\\[");
			tq = regex_replace(tq, wregex(L"\\]"), L"\\]");
			tq = regex_replace(tq, wregex(L"\\("), L"\\(");
			tq = regex_replace(tq, wregex(L"\\)"), L"\\)");
			tq = regex_replace(tq, wregex(L"\\{"), L"\\{");
			tq = regex_replace(tq, wregex(L"\\}"), L"\\}");
			tq = regex_replace(tq, wregex(L"\\|"), L"\\|");
			tq = regex_replace(tq, wregex(L"\\?"), L"\\?");
			tq = regex_replace(tq, wregex(L"\\+"), L"\\+");
			tq = regex_replace(tq, wregex(L"\\*"), L"\\*");
			tq = regex_replace(tq, wregex(L"\\^"), L"\\^");
			tq = regex_replace(tq, wregex(L"\\."), L"\\.");
			tq = regex_replace(tq, wregex(L":b:_:b:"), L"\\\\");
			tqg = regex_replace(tqg, wregex(L"\\{" + tq + L"\\}"), q);
			q = tqg;
		}
		tqg = regex_replace(tqg, wregex(L"::_::"), L"{"); tqg = regex_replace(tqg, wregex(L":s:_:s:"), L"$"); q = tqg;
	}
	return q;
}

static wstring connect(wstring& w, bool bg = 0) {
	bool con = 0;
	wstring qqs = qq.substr(0, qq.find('>') + 1);
	if (bg) { qqs = qq + L">"; con = 1; }
	if (qqs.find(' ') != string::npos
		|| qqs.find(':') != string::npos
		|| qqs.find('-') != string::npos
		) {
		wstring s = qqs.substr(qqs.length() - 2, 2);
		if (
			s == L" >"
			|| s == L":>"
			|| s == L"->"
			) {
			con = 1;
		}
	}
	if (con) {
		vstrand.at(0).out.clear();
		strand = qqs;
		scan_db(vstrand, 1);
		strand.clear();
		if (vstrand.at(0).out[0]) {
			if (delimiter[0] != '\n') { vstrand.at(0).out = regex_replace(vstrand.at(0).out, wregex(L"\n"), L""); vstrand.at(0).out = regex_replace(vstrand.at(0).out, wregex(L"\t"), L""); }
			wstring x = vstrand.at(0).out,
				xx = qq.substr(qqs.length() - bg);
			if (bg)	return x;
			w = x + xx;
			w = isVar(w);
			c = -1;
			if (out_speed > 0) out_sleep = 0;
			return L"";
		}
	}
	printq();
	return L"";
}

static bool qqb(const wstring s) {
	return qq.substr(0, s.length()) == s && qq.find('>') != string::npos;
}

static bool testqqb(const wstring s) {
	return qqb(s) && qq[s.length()] != '>';
}

static void clear_all_keys() {
	if (!ignoreAZ) for (int i = 65; i < 91; ++i) { GetAsyncKeyState(i); }
	if (!ignore09) for (int i = 48; i < 58; ++i) { GetAsyncKeyState(i); }
	if (Kb_Key_Right_Shift[0]) GetAsyncKeyState(VK_RSHIFT);
	if (Kb_Key_Left_Shift[0]) GetAsyncKeyState(VK_LSHIFT);
	//GetAsyncKeyState(VK_BACK);
	if (Kb_Key_Left_Ctrl[0]) GetAsyncKeyState(VK_LCONTROL);
	if (Kb_Key_Right_Ctrl[0]) GetAsyncKeyState(VK_RCONTROL);
	//GetAsyncKeyState(VK_PAUSE);
	if (Kb_Key_Space[0]) GetAsyncKeyState(VK_SPACE);
	if (Kb_Key_Esc[0]) GetAsyncKeyState(VK_ESCAPE);
	if (!ignoreF1s) { GetAsyncKeyState(VK_F1); GetAsyncKeyState(VK_F2); GetAsyncKeyState(VK_F3); GetAsyncKeyState(VK_F4); GetAsyncKeyState(VK_F5); GetAsyncKeyState(VK_F6); GetAsyncKeyState(VK_F7); GetAsyncKeyState(VK_F8); GetAsyncKeyState(VK_F9); GetAsyncKeyState(VK_F10); GetAsyncKeyState(VK_F11); GetAsyncKeyState(VK_F12); }
	if (!ignoreArrows) { GetAsyncKeyState(VK_LEFT); GetAsyncKeyState(VK_UP); GetAsyncKeyState(VK_RIGHT); GetAsyncKeyState(VK_DOWN); }
	if (Kb_Key_Tab[0])GetAsyncKeyState(VK_TAB);
	if (Kb_Key_Left_Alt[0])GetAsyncKeyState(VK_LMENU);
	if (Kb_Key_Right_Alt[0])GetAsyncKeyState(VK_RMENU);
	if (Kb_Key_Enter[0])GetAsyncKeyState(VK_RETURN);
	if (Kb_Key_Caps[0])GetAsyncKeyState(VK_CAPITAL);
	if (Kb_Key_Grave_Accent[0])GetAsyncKeyState(VK_OEM_3);
	if (Kb_Key_Minus[0])GetAsyncKeyState(VK_OEM_MINUS);
	if (Kb_Key_Equal[0])GetAsyncKeyState(VK_OEM_PLUS);
	if (Kb_Key_Left_Bracket[0])GetAsyncKeyState(VK_OEM_4);
	if (Kb_Key_Right_Bracket[0])GetAsyncKeyState(VK_OEM_6);
	if (Kb_Key_Backslash[0])GetAsyncKeyState(VK_OEM_5);
	if (Kb_Key_Semicolon[0])GetAsyncKeyState(VK_OEM_1);
	if (Kb_Key_Quote[0])GetAsyncKeyState(VK_OEM_7);
	if (Kb_Key_Comma[0])GetAsyncKeyState(VK_OEM_COMMA);
	if (Kb_Key_Period[0])GetAsyncKeyState(VK_OEM_PERIOD);
	if (Kb_Key_Forwardslash[0])GetAsyncKeyState(VK_OEM_2);
	if (!ignoreNumPad) { GetAsyncKeyState(VK_NUMLOCK); GetAsyncKeyState(VK_DIVIDE); GetAsyncKeyState(VK_MULTIPLY); GetAsyncKeyState(VK_SUBTRACT); GetAsyncKeyState(VK_ADD); GetAsyncKeyState(VK_RETURN); GetAsyncKeyState(VK_DECIMAL); GetAsyncKeyState(VK_NUMPAD0); GetAsyncKeyState(VK_NUMPAD1); GetAsyncKeyState(VK_NUMPAD2); GetAsyncKeyState(VK_NUMPAD3); GetAsyncKeyState(VK_NUMPAD4); GetAsyncKeyState(VK_NUMPAD5); GetAsyncKeyState(VK_NUMPAD6); GetAsyncKeyState(VK_NUMPAD7); GetAsyncKeyState(VK_NUMPAD8); GetAsyncKeyState(VK_NUMPAD9); }
	if (!ignoreNumPad) { if (Kb_Key_Numlock[0]) GetAsyncKeyState(VK_NUMLOCK); if (Kb_Key_Numpad_Divide[0]) GetAsyncKeyState(VK_DIVIDE); if (Kb_Key_Numpad_Multiply[0]) GetAsyncKeyState(VK_MULTIPLY); if (Kb_Key_Numpad_Minus[0]) GetAsyncKeyState(VK_SUBTRACT); if (Kb_Key_Numpad_Add[0]) GetAsyncKeyState(VK_ADD); if (Kb_Key_Numpad_Enter[0]) GetAsyncKeyState(VK_RETURN); if (Kb_Key_Numpad_Period[0]) GetAsyncKeyState(VK_DECIMAL); if (Kb_Key_Numpad_0[0]) GetAsyncKeyState(VK_NUMPAD0); if (Kb_Key_Numpad_1[0]) GetAsyncKeyState(VK_NUMPAD1); if (Kb_Key_Numpad_2[0]) GetAsyncKeyState(VK_NUMPAD2); if (Kb_Key_Numpad_3[0]) GetAsyncKeyState(VK_NUMPAD3); if (Kb_Key_Numpad_4[0]) GetAsyncKeyState(VK_NUMPAD4); if (Kb_Key_Numpad_5[0]) GetAsyncKeyState(VK_NUMPAD5); if (Kb_Key_Numpad_6[0]) GetAsyncKeyState(VK_NUMPAD6); if (Kb_Key_Numpad_7[0]) GetAsyncKeyState(VK_NUMPAD7); if (Kb_Key_Numpad_8[0]) GetAsyncKeyState(VK_NUMPAD8); if (Kb_Key_Numpad_9[0]) GetAsyncKeyState(VK_NUMPAD9); }
	if (Kb_Key_Insert[0]) GetAsyncKeyState(VK_INSERT); if (Kb_Key_Delete[0]) GetAsyncKeyState(VK_DELETE); if (Kb_Key_Home[0]) GetAsyncKeyState(VK_HOME); if (Kb_Key_End[0]) GetAsyncKeyState(VK_END); if (Kb_Key_PgUp[0]) GetAsyncKeyState(VK_PRIOR); if (Kb_Key_PgDn[0]) GetAsyncKeyState(VK_NEXT);
	if (Kb_Key_Menu[0]) GetAsyncKeyState(VK_APPS); //menu
}

static void print_ctrls() {
	cout << R"(anunnaki keyboard

?+ESC		Help
X+ESC		Exit
H+ESC		Toggle visibility
P+ESC		<xy:>
A+ESC		<ifapp~:>
R+ESC		<ifrgb:>
L+ESC		Toggle [RSHIFT+LSHIFT_Only 2]
G+ESC		RGBXY to clipboard in 3 sec.
Set mouse pointer over target, press G+ESC, then move it away

Syntax
i o		Auto backspace input
i-o
i>o		Remember input for RepeatKey
Press RCTRL after input to run

<x:>1		Link
i <x:>

i		Fallthrough
ii
q 1
Press I, II, or Q RCTRL to run

CtrlKey	options:
RCTRL, F2, RSHIFT+LSHIFT, COMMA+ESC

RepeatKey options:
PAUSE, RCTRL+LCTRL, EQUAL+ESC

Clear input:
Hold RSHIFT, Press LSHIFT three times

Settings
<se>		Reload, print to console. Use SE to only print
<se:>		Load other
<test ><SE>

Database
<db>		Print
<db:>		Load too. Use se.txt [Database] for fresh db

Mouse event
<~>		Set current position
<xy:>		Move to
<xy~:>		Auto set. Use <~~> to return where it was
<lc>		LEFT CLICK
<rc>		RIGHT
<mc>		MIDDLE
<lh>		HOLD
<rh>
<mh>
<lr>		RELEASE
<rr>
<mr>
<sl>		SCROLL LEFT
<su>		UP
<sr>		RIGHT
<sd>		DOWN
<test:><xy: 0 0><lc2>

Window controls:
<ifapp:>	If app is open
<ifapp~:>	Use ~ to move app to foreground
<ifApp:>	Use A to check if app window is in focus

Syntax
<ifapp~: 'title | Title, *, ms n, t: f:'>

Stop if false
<ifapp~: title>

Loop. Check every 160ms
<ifapp~: title,>

Check 3 times. 3000ms delay
<ifapp~: t, 3, 3000>

Loop infinitely
<ifapp~: t, 1, 1000,> or
<ifapp~: t, 1, 1000, :> or - instead of :

Link to false if false
<ifapp~: t, 1, 1, f:>
<f:><'F>

Open true false link slots with SPACE
<ifapp~: t, 1, 1, t: f:>
<t:><<:T>
<f:><<:F>

Continue if true or false. Use <
<ifapp~:t,1,1,< <>

Loop feedback message. Use ' (optional)
<ifapp~:'?'t,1,1,<t: <f:>

Link and continue. Use <
<ifapp~:t, 1, 1, <t: <f:><'1>

Use , in false slot for retry
<ifapp~:'t,1,1,<t: ,><<:1>

Use ' before the closing > for final ms delay (optional)

<test ><ifapp~: '\R?\7'db.txt, 1, 1000, <t: f:'><'true>
<t:><'\Gtrue\W>
<f:><'\Rfalse\W>

Print to console:
<<:x\n>	Custom message        
<'x>	Auto newline
<' x>	No print. Use SPACE
		
Options:
\1-9    Color (or use \012\, \R, \G, \B, \W)
\n      Newline
\t      Tab
\T      Time
\g      >
\c      Cb
\0C\	Toggle

<''x>0		Use '' to dead line to the right
<'''		0 db underneath

Use <anu> to run on start
<anu><'\T>

Keyboard
<ctrl>		Hold key
<shift>
<alt>
<win>
<ctrl->		Release key
<shift->
<alt->
<win->
<up>		Press key
<right>
<down>
<left>
<delete>
<esc>
<bs>
<home>
<end>
<space>
<tab>
<enter>
<pause>
<caps>
<menu>
<win1>

t <shift><left3><shift-><ctrl>x<ctrl->

Sleep
<,>		160 milliseconds
<,1000>		1000 ms
<,10000 40>	Escapable (n). Use SPACE (optional)

Output speed
<speed:160>

Message box. Options: \SPACE \g \n
<yesno: title continue?>

Replace cb
<replace:\r\n x>

<upper>		Uppercase cb
<lower>

Set se.txt [ReplacerDb c:\anu\db.txt] for replacer ability
te {x:}
x:1

Audio:
<Audio: c:\anu\fx.wav>
<audio: play c:\anu\fx.mp3>

Set se.txt [RgbScaleLayout] to match Display settings > Scale & layout. [1.00] is 100%
<ifrgb:>	Continue running if rgbxy is true
<ifrgb~:>	Use ~ to set mouse pointer to x y if r g b is true

Syntax		Use either & or | 
<ifrgb~: 'r g b x y & r g b x y, *, ms n, t: f:'>

<ifcb:>		Options:
<ifcble:>	== != < <= g g=
<ifcbf:>	Regex find
<ifcbF:>	Find
<ifcbS:>	Starts with
<ifcbE:>	Ends with
<ifcblen:>	Length

<ifxy:>

<xy>	Type
<rgb>
<app>	Cb
<cb>	Paste
<cb:>	Set

Manual controls:
<!:>	Set input; return
<!!:>	Set repeat

misc.
Use legacy terminal: Terminal settings > Terminal > Windows Console Host
Use \\\\g for > in <ifapp:>
Other: \, \| \&
)";

}

static void toggle_visibility() {
	if (IsWindowVisible(GetConsoleWindow())) {
		SetForegroundWindow(GetConsoleWindow());
		kb(VK_F12); //if title "Select" x86
		//ShowWindow(GetConsoleWindow(), SW_MINIMIZE);
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
	else {
		ShowWindow(GetConsoleWindow(), SW_RESTORE);
		SetForegroundWindow(GetConsoleWindow());
	}
	sleep(150);
	strand.clear();
}

static wstring getRGB(bool bg = 0) {
	POINT pt;
	GetCursorPos(&pt);

	COLORREF color;
	HDC hDC;
	wstring out = L"";
	hDC = GetDC(NULL);

	if (hDC != NULL) {
		auto x = pt.x, y = pt.y;
		bool cb = 0;

		if (bg) {
			if (!qq[0]) {
				cb = 1;
				sleep(3000);
			}
			else
			{
				wstring ms = qq.substr(4);
				ms = ms.substr(0, ms.find('>'));
				if (ms[0] == ' ') ms = ms.substr(1);

				if (check_if_num(ms, L"<rgb {slot}>") == L"") {
					c = out.length();
					//out = repeats;
					return L"";
				}

				sleep(stoi(ms));
			}
		}

		color = GetPixel(hDC, int(x * RgbScaleLayout), int(y * RgbScaleLayout));
		ReleaseDC(NULL, hDC);

		if (color != CLR_INVALID) {
			wstring c = to_wstring(GetRValue(color)) + L" " + to_wstring(GetGValue(color)) + L" " + to_wstring(GetBValue(color));//cb
			if (bg) {
				if (cb) { //g + esc
					wstring r = L"<ifrgb~:";
					r += c + L" " + to_wstring(x) + L" " + to_wstring(y);
					r += Loop_Insert_Text > L"" ? Loop_Insert_Text : L">";

					cbSet(r);

					return L"";
				}
				qx = to_wstring(x); qy = to_wstring(y);
				return c + L" " + qx + L" " + qy;
			}
			out = L"ifrgb:" + c + L" " + to_wstring(x) + L" " + to_wstring(y) + (Loop_Insert_Text > L"" ? Loop_Insert_Text : L">");

		}
	}
	return out;
}

static wstring getXY() {
	POINT pt; GetCursorPos(&pt);
	wstring xy = to_wstring(pt.x) + L" " + to_wstring(pt.y);
	xy += Loop_Insert_Text > L"" ? Loop_Insert_Text : L">";
	return xy;
}

static wstring getAppT() {
	HWND h = GetForegroundWindow();
	int l = GetWindowTextLength(h);
	wstring title(l, 0);
	GetWindowTextW(h, &title[0], l + 1);
	title = regex_replace(title, wregex(L","), L"\\,");
	title = regex_replace(title, wregex(L">"), L"\\g");
	title = regex_replace(title, wregex(L"\\|"), L"\\|");
	title = regex_replace(title, wregex(L"&"), L"\\&");
	return title;
}

static void if_esc_pause(Multi_ multi_) {
	GetAsyncKeyState(VK_ESCAPE); if (GetAsyncKeyState(VK_ESCAPE))
		stop = 1;

	GetAsyncKeyState(PauseKey); if (GetAsyncKeyState(PauseKey)) {

		multi_.out_ = out;
		multi_.qq_ = qq;
		multi_.qp_ = qp;
		multi_.strand_ = strand;
		multi_.c_ = c;

		while (GetAsyncKeyState(PauseKey) != 0)
			sleep(frequency / 3);

		if (show_strand)
			cout << "PAUSE\n";

		string q = "~PAUSE\n";
		out_speed = 0;

		while (1) {
			GetAsyncKeyState(PauseKey); if (GetAsyncKeyState(PauseKey)) { while (GetAsyncKeyState(PauseKey) != 0) { sleep(frequency / 3); } break; }

			GetAsyncKeyState(VK_ESCAPE); if (GetAsyncKeyState(VK_ESCAPE)) { q = "~ESC\n"; kb_release(VK_ESCAPE); break; }

			sleep(frequency);
		}

		if (show_strand)
			cout << q;

		if (q[1] == 'E') //~ESC
			stop = 1;

		if (!stop) {
			out = multi_.out_;
			qq = multi_.qq_;
			qp = multi_.qp_;
			strand = multi_.strand_;
			c = multi_.c_;
		}
	}
}

static void multi_sleep(Multi_ multi_, unsigned short ms, unsigned short n = 1) {
	if (ms > 0) {
		multi_.out_ = out;
		multi_.qq_ = qq;
		multi_.qp_ = qp;
		multi_.c_ = c;

		if (n > 1) {
			for (size_t i = 0; i < n; ++i) {
				if_esc_pause(multi_);
				if (stop) { break; }
				this_thread::sleep_for(chrono::milliseconds(ms / n));
			}
		}
		else
			this_thread::sleep_for(chrono::milliseconds(ms));

		out = multi_.out_;
		qq = multi_.qq_;
		qp = multi_.qp_;
		c = multi_.c_;
	}
}

static inline void clear_key(wchar_t key) {
	if (key > 64 && key < 91) //clear key
		GetAsyncKeyState(key); //A-Z
	else if (key > 96 && key < 123)
		GetAsyncKeyState(key - 32); //a-z
	else {
		auto x = 0;
		switch (key) {
		case '\b': x = 8; break;
		case ' ': x = 32; break;
		case '"':
		case '\'': x = 39; break;
		case '<':
		case ',': x = 44; break;
		case '_':
		case '-': x = 45; break;
		case '>':
		case '.': x = 46; break;
		case '?':
		case '/': x = 47; break;
		case ')':
		case '0': x = 48; break;
		case '!':
		case '1': x = 49; break;
		case '@':
		case '2': x = 50; break;
		case '#':
		case '3': x = 51; break;
		case '$':
		case '4': x = 52; break;
		case '%':
		case '5': x = 53; break;
		case '^':
		case '6': x = 54; break;
		case '&':
		case '7': x = 55; break;
		case '*':
		case '8': x = 56; break;
		case '(':
		case '9': x = 57; break;
		case ';':
		case ':': x = 58; break;
		case '+':
		case '=': x = 61; break;
		case '{':
		case '[': x = 91; break;
		case '|':
		case '\\': x = 92; break;
		case '}':
		case ']': x = 93; break;
		case '~':
		case '`': x = 96; break;
		}
		GetAsyncKeyState(x);
	}
}

static void scan_db(vector<Strand> const& vdb, bool ret = 0) {

	bool fallthrough_ = 0, found_io = 0;

	for (size_t i = 0; i < vdb.size(); ++i)
	{
		//return_connect
		if (ret && vdb.at(i).in[0] != '<')
			continue;

		if (repeats[0] == '>'
			|| fallthrough_
			|| close_ctrl_mode && vdb.at(i).in == strand.substr(0, strand.length() - 1 + ret)
			|| vdb.at(i).in[0] == '<' &&
				vdb.at(i).in.substr(0, vdb.at(i).in.length() - vdb.at(i).g.length())
				== strand.substr(0, strand.length() - 1 + ret)
			|| !close_ctrl_mode && vdb.at(i).in == strand
			|| !close_ctrl_mode && vdb.at(i).in == strand + vdb.at(i).g
			) {

			if (ret) {
				vstrand.at(0).out = vdb.at(i).out;
				return;
			}

			if (out[0]) out.clear();

			if (repeats[0] == '>') {
				repeats = repeats.substr(1);
				if (!repeats[0]) return;
				out = repeats;
			}
			else {
				repeat_switch = 0;

				//fallthrough
				if (fallthrough_ && vdb.at(i).out[0]) fallthrough_ = 0;
				if (fallthrough_ && !vdb.at(i).in[0]) return;
				if (!vdb.at(i).out[0]) { fallthrough_ = 1; continue; }

				//backspace input depending on g and set repeat and input accordingly
				switch (vdb.at(i).g[0])
				{
				case '>':
					repeats = vdb.at(i).in + vdb.at(i).out;
					out = vdb.at(i).out;
					break;
					//case ' ':
					//case '-':
				default:
					for (size_t n = 0; n < strand.length(); ++n) {
						wchar_t x = strand[n];
						if (x == '<') continue;
						bs_input(x);
					}
					[[fallthrough]];
				case ':':
					out = repeats = vdb.at(i).out;
				}

			}

			//run output

			if (replacerDb[0]) out = isVar(out); //<r:>

			if (delimiter[0] != '\n') {
				out = regex_replace(out, wregex(L"\n"), L"");
				out = regex_replace(out, wregex(L"\t"), L"");
			}

			Multi_ multi_;

			if (strand[0]) strand.clear();

			found_io = 1;

			for (c = 0; c < out.length(); ++c) {

				if_esc_pause(multi_);
				if (stop) { stop = 0; break; }

				if (out_speed > 0) {
					if (out_sleep) {
						if (c)
							multi_sleep(multi_, out_speed);
					}
					out_sleep = 1;
				}

				switch (out[c]) { //extracted
				case '<':
					qq = out.substr(c, out.length() - c); //<test>
					if (qq.substr(0, qq.find('>')).find(':') != std::string::npos) { //<test:#>
						qp = qq.substr(qq.find(':') + 1, qq.find('>') - qq.find(':') - 1);//#
						if (qp[0]) {
							if (qp[0] == ' ') qp = qp.substr(1);
							setQxQy(qp);
						}
						if (delimiter[0] != '\n') { qp = regex_replace(qp, wregex(L"\n"), L""); qp = regex_replace(qp, wregex(L"\t"), L""); }
					}
					switch (qq[1]) {
					case '<':
						if (testqqb(L"<<:")) {//cout
							showOutsMsg(L"", qp, L"", 1);
							rei();
							break;
						}
						else connect(out);
						break;
					case '#':
						if (testqqb(L"<#:")) {//ascii_calc
							if (qp.find('\\') != string::npos) qp = regex_replace(qx, wregex(L"\\\\g"), L">");
							int s{}; for (auto& x : qp) s += x;
							auto q = to_wstring(s);	cbSet(q);
							rei();
						}
						else connect(out);
						break;
					case '!':
						if (testqqb(L"<!:")) { //set strand
							strand = qp;
							prints();
							return;
						}
						else if (testqqb(L"<!!:") || testqqb(L"<!!!:")) { //set repeat
							wstring v = qq.substr(qq.find(':') + 1);
							v = v.substr(0, v.find('>'));
							if (qq[qq.find(':') + 1] != '<')
								num_error(L"Not a link", v, L"VALUE:");
							else {
								if (qq[3] == '!') { multi_.store_ = out; multi_.qq_ = qq; } //!!!
								qq = v;
								v = connect(v, 1);
								if (!v[0]) {
									kb(VK_BACK); GetAsyncKeyState(VK_BACK);
									sleep(frequency / 2);
									num_error(L"Not found", qq, L"VALUE:");
								}
								else {
									repeats = v;

									if (multi_.store_[0]) { //!!! run
										multi_.c_ = c;
										repeat(vdb);
										sleep(1);
										out = multi_.store_.substr(multi_.c_);
										c = 0;
									}

									qq = out;
									rei();
								}
							}
						}
						else connect(out);
						break;
					case '~':
						if (qqb(L"<~>")) {//manual set xy
							POINT pt; GetCursorPos(&pt); qxcc = pt.x; qycc = pt.y; rei();
						}
						else if (qqb(L"<~~>")) {//manual return xy
							SetCursorPos(qxcc, qycc); rei();
						}
						else connect(out);
						break;
					case'+': //calc
					case'-':
					case'*':
					case'/':
					case'%':
						if (qq[2] == '>' || qq[3] != '>') { //<+:>
							if (qq[3] == ' ') { //<+: #>
								wstring cb = cbGet();
								wstring e = cb;
								if (!e[0] || check_if_num(e, L"clipboard") == L"") { connect(out); continue; }
								multi_.icp_ = stod(cb);
							}

							bool b = 0;
							wstring e = qp;
							if (qq[2] == '>' && qq[1] == '+') b = 1; //<+>
							else if (check_if_num(qp, qq.substr(0, qq.find('>')) + L">") == L"") {
								connect(out);
								continue;
							}

							if (b) {}
							else {
								if (qq[2] != ':') { connect(out); continue; }
								switch (qq[1]) {
								case'+': multi_.icp_ += stod(qp); break; // <+:>
								case'-': multi_.icp_ -= stod(qp); break;
								case'*': multi_.icp_ *= stod(qp); break;
								case'/':
								case'%': if (stoi(qp) <= 0) { printq(); continue; }
									   int x = (int)multi_.icp_; if (qq[1] == '/')
										   multi_.icp_ /= stod(qp);
									   else multi_.icp_ = x % stoi(qp);
								}
							}

							static bool dp;
							if (qp.find('.') != string::npos || qq[3] == ' ' && cbGet().find('.') != string::npos) dp = 1; else { if (!b) dp = 0; }

							wstring x = to_wstring(multi_.icp_);
							if (!dp || qq[1] == '%') x = x.substr(0, x.find(L"."));

							if (qq[3] == ' ') cbSet(x);

							if (b) {
								out = x + qq.substr(qq.find('>') + 1);
								c = -1;
								if (out_speed > 0) out_sleep = 0;
								ic = multi_.icp_;
							}
							else rei();
						}
						else connect(out);
						break;
					case ',':
						if (qqb(L"<,") && qq[2] != ':' && qq[2] != '-') { //<,#>
							qx = qq.substr(2);
							qx = qx.substr(0, qx.find('>'));
							unsigned short n = 1;
							if (qx.find(' ') != string::npos) {
								setQxQy(qx);
								if (check_if_num(qy, L"<,# #>") == L"") return;
								n = stoi(qy); //<,1000 4>
							}
							if (!qx[0]) qx = to_wstring(frequency); //default <,>
							//if (qx[0] < '0' || qx[0] > '9' || n == 0) { //<,1000>
							if (check_if_num(qx, L"<,#>") == L"" || n == 0) { //<,1000>
								rei(); return;
							}

							unsigned short ms = stoi(qx);

							multi_sleep(multi_, ms, n);

							rei();
						}
						else connect(out);
						break;
					case'\'':
						if (qqb(L"<''")) c = out.length();//<''ignore>...
						else if (qqb(L"<'")) { //<'comments>
							if (show_strand) {
								if (qq[2] != ' ') {
									wstring v = qq.substr(2, qq.find('>') - 2);
									showOutsMsg(L"", v, L"\n", 1);
								}
							}
							rei();
							out_sleep = 0;
							break;
						}
						else connect(out);
						break;
					case'a':
					case 'A':
						switch (qq[2]) {
						case 'l':
							if (qqb(L"<alt>")) { kb_hold(VK_LMENU); rei(); }
							else if (qqb(L"<alt->")) { kb_release(VK_LMENU); rei(); }
							else if (qqb(L"<alt")) kb_press(L"<alt", VK_LMENU);
							else connect(out);
							break;
						case 'p':
							if (qqb(L"<app>")) {//app title to cb
								wstring a(getAppT());
								cbSet(a);
								rei();
							}
							else connect(out);
							break;
						case 'u':
							if (testqqb(L"<Audio:") || testqqb(L"<audio:")) {
								if (qq[1] == 'A') sndPlaySoundW((qp).c_str(), SND_FILENAME | SND_ASYNC); else mciSendStringW((qp).c_str(), 0, 0, 0); //<audio:play test.mp3>
								rei();
							}
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'b':
						if (qqb(L"<bs")) kb_press(L"<bs", VK_BACK);
						else connect(out);
						break;
					case'c':
					case'C':
						switch (qq[2]) {
						case 'l':
							if (qqb(L"<cl>")) { wstring l = cbGet(); l = to_wstring(l.length()); cbSet(l); rei(); }
							else connect(out);
							break;
						case 't':
							if (qqb(L"<ctrl>")) { kb_hold(VK_CONTROL); rei(); }
							else if (qqb(L"<ctrl->")) { kb_release(VK_CONTROL); rei(); }
							else if (qqb(L"<ctrl")) kb_press(L"<ctrl", VK_CONTROL);
							else connect(out);
							break;
						case 'b':
							if (testqqb(L"<cb>") || testqqb(L"<cb:")) {
								if (qq[3] == '>') {
									kb_hold(VK_CONTROL); kb('v'); kb_release(VK_CONTROL);
								}
								else if (qq[3] == ':') {
									if (npos_find(qp, '\\', 1)) qp = regex_replace(qp, wregex(L"\\\\\\\\\\\\\\\\g"), L">"); // \\\\g
									//replace_q(qp, L">", L"g");
									cbSet(qp);
								}
								rei();
							}
							else connect(out);
							break;
						case 'a':
							if (qqb(L"<caps")) kb_press(L"<caps", VK_CAPITAL);
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'd':
					case'D':
						switch (qq[2]) {
						case 'B':
						case 'b':
							if (testqqb(L"<DB:") || testqqb(L"<db:")) {//.h Database:
								if (qq[1] == 'D') showOutsMsg(L"", qp, L"", 0);
								qp = regex_replace(qp, wregex(L"/"), L"\\");
								wifstream f(qp); if (!f) { showOutsMsg(L"", L"\\n\\4Database \\7\\0C\\" + qp + L"\\0C\\\\4 not found!\\7\\n", L"", 1); return; }
								rei();
								//append db
								wstring t = qp;
								database = qp;
								mvdb = 2;
								vstrand = make_vdb_table();
								database = t;
								break;
							}
							else if (qqb(L"<db>")) { 
								for (size_t i = 0; i < vdb.size(); ++i) {
									auto in_ = vdb.at(i).in[0] && vdb.at(i).in[vdb.at(i).in.length() - 1] == '>' ? L"" : vdb.at(i).g;
									wcout << i << L": " << vdb.at(i).in << in_ << vdb.at(i).out << L"\n";
								}
								rei();
							}
							else connect(out);
							break;
						case 'o':
							if (qqb(L"<down")) kb_press(L"<down", VK_DOWN);
							else connect(out);
							break;
						case 'n':
							if (qqb(L"<dna:")) {
								if (npos_find(qp, '\\', 1)) qp = regex_replace(qp, wregex(L"\\\\\\\\\\\\\\\\g"), L">"); // \\\\g
								HWND h = GetConsoleWindow(); SetConsoleTitleW(qp.c_str()); rei();
							}
							else connect(out);
							break;
						case 'e':
							if (qqb(L"<delete")) kb_press(L"<delete", VK_DELETE);
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'e':
						switch (qq[3]) {
						case 't':
							if (qqb(L"<enter")) kb_press(L"<enter", VK_RETURN);
							else connect(out);
							break;
						case 'd':
							if (qqb(L"<end")) kb_press(L"<end", VK_END);
							else connect(out);
							break;
						case 'c':
							if (qqb(L"<esc")) kb_press(L"<esc", VK_ESCAPE);
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'f':
						switch (qq[2]) {
						case '1':
							if (qqb(L"<f10")) kb_press(L"<f10", VK_F10);
							else if (qqb(L"<f11")) kb_press(L"<f11", VK_F11);
							else if (qqb(L"<f12")) kb_press(L"<f12", VK_F12);
							else if (qqb(L"<f1")) kb_press(L"<f1", VK_F1);
							else connect(out);
							break;
						case '2':
							if (qqb(L"<f2")) kb_press(L"<f2", VK_F2);
							else connect(out);
							break;
						case '3':
							if (qqb(L"<f3")) kb_press(L"<f3", VK_F3);
							else connect(out);
							break;
						case '4':
							if (qqb(L"<f4")) kb_press(L"<f4", VK_F4);
							else connect(out);
							break;
						case '5':
							if (qqb(L"<f5")) kb_press(L"<f5", VK_F5);
							else connect(out);
							break;
						case '6':
							if (qqb(L"<f6")) kb_press(L"<f6", VK_F6);
							else connect(out);
							break;
						case '7':
							if (qqb(L"<f7")) kb_press(L"<f7", VK_F7);
							else connect(out);
							break;
						case '8':
							if (qqb(L"<f8")) kb_press(L"<f8", VK_F8);
							else connect(out);
							break;
						case '9':
							if (qqb(L"<f9")) kb_press(L"<f9", VK_F9);
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'h':
						if (qqb(L"<home")) kb_press(L"<home", VK_HOME);
						else connect(out);
						break;
					case'i':
						switch (qq[2]) {
						case 'f':
							if (testqqb(L"<ifapp") || testqqb(L"<ifApp") //app activate, if App in foreground
								|| testqqb(L"<ifrgb")
								|| testqqb(L"<ifxy")
								|| testqqb(L"<ifcb")
								) {
#pragma region ifinit
								if (!qp[0]) { connect(out); break; }

								wstring t{};
								wstring a{};
								wstring x{};
								wstring ms{};
								wstring tf{};
								wstring tf_T{};
								wstring tf_F{};
								wstring tf_feedback{};
								wstring R{}, G{}, B{}, X{}, Y{};

								unsigned short slash_pipes = 0;
								unsigned short slash_ands = 0;
								unsigned short slash_commas = 0;
								unsigned short ands = 0;
								unsigned short commas = 0;
								unsigned short pipes = 0;
								unsigned short spaces = 0;

								bool sleeper_tick{}; //last ' for final sleep. <ifapp~:...'>
								bool tf_T_link{}; //x:
								bool tf_F_link{};
								bool tf_T_link_plus_connect{}; //<x:
								bool tf_F_link_plus_connect{};
								bool tf_T_continue{}; //<
								bool tf_F_continue{};
								bool tf_F_retry{}; // ,
								bool tf_loop{}; // : -

								if (qp.substr(qp.length() - 1, 1) == L"'") {
									sleeper_tick = 1;
									qp = qp.substr(0, qp.length() - 1);
								}

								t = qp;

								for (size_t i = 0; i < qp.length(); ++i)
								{
									if (qp.length() == 1) break;
									if (qp[i] == ',') {
										if (qp[i - 1] == '\\') {
											++slash_commas;
											continue;
										}
										++commas;
										continue;
									}
									if (qp[i] == '|') {
										if (qp[i - 1] == '\\') {
											++slash_pipes;
											continue;
										}
										++pipes;
										continue;
									}
									if (qp[i] == '&') {
										if (qp[i - 1] == '\\') {
											++slash_ands;
											continue;
										}
										++ands;
										continue;
									}
								}

								for (size_t i = 0; i <= slash_commas; ++i, t = t.substr(t.find(',') + 1))
								{
									if (!commas && i == slash_commas) { t = qp; break; }
								}

								//		<app: db.txt, 1, 1000 4, t: f:>
								//set	<app: a,	  x, ms   n,  tf  >
								if (!a[0]) {
									a = qp.substr(0, qp.length() - t.length() - 1);
									//set default loop <app:a,>
									if (commas == 1) { tf_loop = 1; ms = to_wstring(frequency * 4); x = L"1"; }
									//set <app:'feedback'a,>
									if (a[0] == '\'') {
										tf_feedback = a.substr(1);
										if (npos_find(tf_feedback, '\'', 1)) {
											tf_feedback = tf_feedback.substr(0, tf_feedback.find('\''));
											a = a.substr(tf_feedback.length() + 2);
										}
										else {
											tf_feedback = L"'";
											a = a.substr(tf_feedback.length());
										}
									}
								}
								if (!x[0] && commas) { x = t.substr(0, t.find(',')); t = t.substr(t.find(',') + 1); if (x[0] == ' ') x = x.substr(1); }
								if (!ms[0] && commas > 1) { ms = t.substr(0, t.find(',')); t = t.substr(t.find(',') + 1); if (ms[0] == ' ') ms = ms.substr(1); }
								if (!tf[0] && commas > 2) {
									tf = t; if (tf[0] == ' ') tf = tf.substr(1); // set

									if (tf[0] && npos_find(tf, ' ', 1)) { //t: f: slot
										tf_T = tf.substr(0, tf.find(' '));
										tf_F = tf.substr(tf.find(' ') + 1);

										//lint x:
										if (tf_T.length() >= 1 && (npos_find(tf_T, ':', 1) || npos_find(tf_T, '-', 1))) {
											//link_plus_connect <x:
											if (tf_T[0] == '<')
												tf_T_link_plus_connect = 1;
											else
												tf_T_link = 1;
										}
										if (tf_F.length() >= 1 && (npos_find(tf_F, ':', 1) || npos_find(tf_F, '-', 1))) {
											if (tf_F[0] == '<')
												tf_F_link_plus_connect = 1;
											else
												tf_F_link = 1;
										}

										//continue <
										if (tf_T == L"<") tf_T_continue = 1;
										if (tf_F == L"<") tf_F_continue = 1;

										//retry ,
										if (tf_F == L",") tf_F_retry = 1;

									}
									else if (tf == L":" || tf == L"-" || !tf[0])
										tf_loop = 1;
									else if (tf == L"<")
										tf_F_continue = 1; //single tf_F continue
									else if (tf.length() >= 1 && (npos_find(tf, ':', 1) || npos_find(tf, '-', 1))) {
										if (tf[0] == '<') //single tf_F case
											tf_F_link_plus_connect = 1;
										else
											tf_F_link = 1;
									}

									if (debug == 1) {
										wcout << tf << " tf\n";
										cout << tf_loop << " tf_loop\n";
										cout << tf_T_link << " tf_T_link\n";
										cout << tf_F_link << " tf_F_link\n";
										cout << tf_T_link_plus_connect << " tf_T_link_plus_connect\n";
										cout << tf_F_link_plus_connect << " tf_F_link_plus_connect\n";
										cout << tf_T_continue << " tf_T_continue\n";
										cout << tf_F_continue << " tf_F_continue\n";
										cout << tf_F_retry << " tf_F_retry\n";
									}
								}

								if (a.find('\\') != string::npos) {
									a = regex_replace(a, wregex(L"\\\\,"), L","); // \,
									a = regex_replace(a, wregex(L"\\\\\\\\\\\\\\\\g"), L">"); // \\\\g
								}

								vector<wstring>p{};
								if (pipes) {
									t = a;
									t = regex_replace(t, wregex(L"[\\s][\\\\\\|][\\s]"), L"|");
									if (slash_pipes) t = regex_replace(t, wregex(L"\\\\\\|"), L"  ");

									for (unsigned short i = 0; i < pipes + 1; ++i)
									{
										wstring v = t.substr(0, t.find('|'));
										if (slash_pipes) v = regex_replace(v, wregex(L"  "), L"|");
										p.push_back(v);
										t = t.substr(t.find('|') + 1);
									}

								}
								else if (ands) {
									t = a;
									t = regex_replace(t, wregex(L"[\\s][&][\\s]"), L"&");
									if (slash_ands) t = regex_replace(t, wregex(L"[\\&]"), L"  ");

									for (unsigned short i = 0; i < ands + 1; ++i)
									{
										wstring v = t.substr(0, t.find('&'));
										if (slash_ands) v = regex_replace(v, wregex(L"  "), L"&");
										p.push_back(v);
										t = t.substr(t.find('&') + 1);
									}

								}
								else p.push_back(a);

								unsigned short x_times{};
								if (x[0]) {
									if (check_if_num(x, L"* slot") == L"")
										break;
									else x_times = stoi(x);
								}
								else x_times = 1;

								unsigned short ms_milliseconds{}, n = 1;
								if (ms[0]) {
									if (npos_find(ms, ' ', 1)) { //set ms_milliseconds
										t = ms.substr(0, ms.find(' ')); //1000 4
										if (check_if_num(t) == L"") { num_error(L"ms slot", t); break; }
										else ms_milliseconds = stoi(t);
										t = ms.substr(ms.find(' ') + 1);
										if (check_if_num(t) == L"") { num_error(L"ms n slot", t); break; }
										else n = stoi(t);
									}
									else
										if (check_if_num(ms, L"ms slot") == L"") break;
										else ms_milliseconds = stoi(ms);
								}
								else ms_milliseconds = 0;
#pragma endregion
								//<if inits
								if (qq[3] == 'r') {
									for (size_t i = 0; i < a.length(); ++i)
										if (a[i] == ' ') ++spaces;
								}

								unsigned short count = 0;

								for (size_t i = 0; i < x_times; ++i)
								{
									if_esc_pause(multi_);
									if (stop) break;

									if (tf_loop || tf_F_retry) ++x_times;

									for (size_t j = 0; j < p.size(); ++j)
									{
										if (p[j] == L"") {
											wstring e = qq.substr(0, 6) + L"> \\4NO VALUE FOUND. \\7USE ONE "; e += pipes ? L"|\\n" : L"&\\n"; showOutsMsg(L"", e, L"", 1);
											stop = 1; break;
										}

										//if loops
										switch (qq[3]) {
											case 'a':
											case 'A': {
												HWND h{}, h1{}; DWORD pid{};

												if (qq[3] == 'A') { //ifApp
													h = GetForegroundWindow(); h1 = FindWindowW(0, p[j].c_str());
													if (h == h1) ++count;
												}
												else if (qq[3] == 'a') { //'ifapp
													h = FindWindowW(0, p[j].c_str()); GetWindowThreadProcessId(h, &pid);
													if (h) {
														if (IsIconic(h)) { ShowWindow(h, SW_RESTORE); ShowWindow(h, SWP_SHOWWINDOW); }
														if (qq[6] == '~') SetForegroundWindow(h); //ifapp~
														++count;
													}
												}
												break;
											}
											case 'r': {
												R = L"", G = L"", B = L"", X = L"", Y = L"";
												t = L" " + p[j];
												for (unsigned short i = 0; i < spaces + 1; ++i) {
													t = t.substr(t.find(' ') + 1);
													if (!R[0]) { R = t.substr(0, t.find(' ')); continue; }
													if (!G[0]) { G = t.substr(0, t.find(' ')); continue; }
													if (!B[0]) { B = t.substr(0, t.find(' ')); continue; }
													if (!X[0]) { X = t.substr(0, t.find(' ')); continue; }
													if (!Y[0]) { Y = t; break; }
												}

												if (debug == 1) {
													t = R + G + B + X + Y;
													t = regex_replace(a, wregex(L"-"), L"");
													if (check_if_num(t, L"CHECK RGBXY slot") != L"") { stop = 1; break; }
												}

												POINT pt;
												COLORREF color;
												HDC hDC;
												hDC = GetDC(NULL);
												if (X[0]) { color = GetPixel(hDC, int(stoi(X) * RgbScaleLayout), int(stoi(Y) * RgbScaleLayout)); }
												else { GetCursorPos(&pt); color = GetPixel(hDC, int(pt.x * RgbScaleLayout), int(pt.y * RgbScaleLayout)); }
												ReleaseDC(NULL, hDC);
												if (color != CLR_INVALID
													&& GetRValue(color) == stoi(R)
													&& GetGValue(color) == stoi(G)
													&& GetBValue(color) == stoi(B))
													++count; //&
										
												break;
											}
											case 'x': {
												auto q = p[j].find(' ');
												auto x = p[j].substr(0, q), y = p[j].substr(q + 1);
												POINT pt; GetCursorPos(&pt);
												if (x == L".") x = to_wstring(pt.x);
												if (y == L".") y = to_wstring(pt.y);
												auto tx = stoi(x), ty = stoi(y);

												switch (qq[5]) {
													case ':': //== <ifxy:> <ifxy=:> <ifxye:>
													case '=':
													case 'e': {
														if (pt.x == tx && pt.y == ty) ++count = 1;
														break;
													}
													case 'n': //!= <ifxyn:> <ifxy!:>
													case '!': {
														if (pt.x != tx && pt.y != ty) ++count = 1;
														break;
													}
													case 'l'://<= <ifxyl:> <ifxyle:> <ifxy<:> <ifxy<=:>
													case 'L':
													case '<': {
														if (qq[6] == 'e' || qq[6] == '=') { if (pt.x <= tx && pt.y <= ty) { ++count = 1; break; } } //ifxyle <=
														if (pt.x < tx && pt.y < ty) ++count = 1;
														break;
													}
													case 'g': { //>= <ifxyg:> <ifxyge:> <ifxyg=:>
														if (qq[6] == 'e' || qq[6] == '=') { if (pt.x >= tx && pt.y >= ty) { ++count = 1; break; } } //ifxyge >=/g=
														if (pt.x > tx && pt.y > ty) ++count = 1;
														break;
													}
												}
											
												break;
											}
											case 'c': {
												HANDLE hcb;
												wchar_t* cb;
												wstring w;

												OpenClipboard(0);
												hcb = GetClipboardData(CF_UNICODETEXT);
												if (hcb != nullptr) {
													cb = static_cast<wchar_t*>(GlobalLock(hcb));
													if (cb != nullptr)
														w = cb;
												}
												CloseClipboard();

												switch (qq[5]) {
													case ':': //== <ifcb:> <ifcb=:> <ifcbe:>
													case '=':
													case 'e':
														if (w == p[j]) ++count;
														break;
													case 'A': //<if cb find y starting @ offset x: x y> | <ifcba:1 test>
													case 'a': { //<if cb substring from index x matches y: x y> | <ifcbA:0 test>
														auto x = p[j].substr(0, p[j].find(' ')), y = p[j].substr(p[j].find(' ') + 1);
														if (qq[5] == 'A') {
															auto s = stoi(x) - 1;
															if (w.find(y, s) != wstring::npos)
																++count;
														}
														else { //'a'
															if (w.substr(stoi(x), y.length()) == y)
																++count;
														}
														break;
													}
													case 'S': //if cb starts with | <ifcbS:test>
														if (w.starts_with(p[j]))
															++count;
														break;
													case 'E': //<ifcbE:>
														if (w.ends_with(p[j]))
															++count;
														break;
													case 'n': //!= <ifcbn:> <ifcb!:>
													case '!':
														if (w != p[j])
															++count;
														break;
													case 'f': //<ifcbf:>
														if (regex_search(w, wregex(p[j])))
															++count;
														break;
													case 'F': //<ifcbF:>
														if (w.find(p[j]) != string::npos)
															++count;
														break;
													case 'l'://<= <ifcbl:> <ifcble:> <ifcb<:> <ifcb<=:> || <ifcblen:>
													case 'L':
													case '<': {
														if (check_if_num(p[j], L"a slot") != L"" && check_if_num(w, L"clipboard") != L"") {
															if (qq.substr(5, 3) == L"len") { //length <ifcblen:> <ifcbleng:>
																unsigned short len = stoi(p[j]);
																if (qq[8] == '!' || qq[8] == 'n') { if (w.length() != len) { ++count; break; } }
																else if (qq.substr(8, 2) == L"ge" || qq.substr(8, 2) == L"g=") { if (w.length() >= len) { ++count; break; } }
																else if (qq.substr(8) == L"g") { if (w.length() > len) { ++count; break; } }
																else if (qq.substr(8, 2) == L"le" || qq.substr(8, 2) == L"<e" || qq.substr(8, 2) == L"<=") { if (w.length() <= len) { ++count; break; } }
																else if (qq[8] == 'l' || qq[8] == '<') { if (w.length() < len) { ++count; break; } }
																else if (qq[8] == ':' || qq[8] == 'e' || qq[8] == '=') { if (w.length() == len) ++count; break; }//==
																else { p[j].clear(); ++count; break; }
															}
															if (qq[6] == 'e' || qq[6] == '=') { if (a == L"0" && w == L"0" || stod(w) <= stod(a)) { ++count; break; } } //ifcble <=
															if (stod(w) < stod(a)) ++count;
														}
														else {
															stop = 1;
															c = out.length();
														}
														break;
													}
													case 'g': { //>= <ifcbg:> <ifcbge:> <ifcbg=:>
														if (check_if_num(p[j], L"a slot") != L"" && check_if_num(w, L"clipboard") != L"") {
															if (qq[6] == 'e' || qq[6] == '=') { if (p[j] == L"0" && w == L"0" || stod(w) >= stod(p[j])) { ++count; break; } } //ifcbge >=/g=
															if (stod(w) > stod(p[j])) ++count;
														}
														break;
													}
												}

												break;
											}
										}

										if (stop) break;

										if (ands ? count == p.size() : count) multi_.br_ = 1;
										if (multi_.br_) break;

									}

									if (stop) break;

									if (tf_feedback[0]) if (tf_feedback.length() > 1) showOutsMsg(L"", tf_feedback, L"", 1); else wcout << tf_feedback;

									if (multi_.br_) {
										if (sleeper_tick) multi_sleep(multi_, ms_milliseconds, n);
										break;
									}

									ms_milliseconds = multi_.br_ || !tf_loop && x_times == i + 1 && !multi_.br_ ? 0 : ms_milliseconds;
									multi_sleep(multi_, ms_milliseconds, n);

								}

								if (stop) { stop = 0; c = out.length(); break; }

								if (qq[3] == 'r' && qq[6] == '~' && multi_.br_ && !stop)
									SetCursorPos(stoi(X), stoi(Y));

								if (tf_T[0] || tf_F[0] || tf[0] && !tf_F[0]) {
									if (tf_T_continue && multi_.br_ || tf_F_continue && !multi_.br_ || tf_loop) { rei(); break; }
									tf_T = multi_.br_ ? tf_T : tf_F;
									if (!tf_F[0]) tf_T = tf;//single tf !tf_F[0] case
									tf_T = tf_T + L">";
									if (tf_T_link && multi_.br_ || tf_F_link && !multi_.br_ || !tf_F[0] && tf_F_link) tf_T = L"<" + tf_T;
									wstring l = qq.substr(qq.find('>') + 1);
									qq = tf_T;
									connect(tf_T);
									out = tf_T_link_plus_connect && multi_.br_ || tf_F_link_plus_connect && !multi_.br_ || !tf_F[0] && tf_F_link_plus_connect ? tf_T + l : tf_T;
									break;
								}

								if (!multi_.br_) { c = out.length(); break; }

								rei();

								multi_.br_ = 0;

							}
							else if (testqqb(L"<if+")) {//<if+:> | stop if <+>
								wstring x = qp.substr(0, qp.find(' '));
								if (check_if_num(x) == L"" || !qp[0]) { connect(out); break; }

								bool b = 0; int q = stoi(qp.substr(0, qp.find(' ')));
								wstring l = L""; if (qp.find(' ') != string::npos) l = qp.substr(qp.find(' ') + 1);//<if+:# true:>
								switch (qq[4]) {
								default:
								case ':': //==
								case 'e':
								case '=':
									if (multi_.icp_ == q) b = 1;
									break;
								case 'n': //!=
								case '!':
									if (multi_.icp_ != q) b = 1;
									break;
								case 'l': //<=
								case 'L':
								case '<':
									if (qq[5] == '=' || qq[5] == 'e') {
										if (qp <= to_wstring(multi_.icp_)) b = 1;
									} //if+le <=
									else {
										if (multi_.icp_ < q) b = 1;
									}
									break;
								case 'g': //g=
									if (qq[5] == '=' || qq[5] == 'e') {
										if (multi_.icp_ >= q) b = 1;
									} //if+ge >=/g=
									else {
										if (multi_.icp_ > q) b = 1;
									}
								}
								if (b) {
									if (l > L"") {
										out = l[0] == '<'
											? l + L">" + qq.substr(qq.find('>') + 1)
											: L"<" + l + L">";//<if+:# true->
										if (out_speed > 0) out_sleep = 0;
										c = -1; break;
									}
									c = out.length(); break;
								}
								else rei();
							}
							else connect(out);
							break;
						case 'n':
							if (qqb(L"<ins")) kb_press(L"<ins", VK_INSERT);
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'l':
						switch (qq[2]) {
						case 'o': //lowercase cb
							if (qqb(L"<lower>")) {
								wstring s = L"", b = L"";
								b = cbGet();
								for (size_t x = 0; x < b.length(); x++)
									s += tolower(b[x]);
								cbSet(s);
								rei();
							}
							else connect(out);
							break;
						case 'c':
							if (qqb(L"<lc"))
								kb_press(L"<lc", VK_F7);//left click
							else
								connect(out);
							break;
						case 'h':
							if (qqb(L"<lh>")) { //left hold
								mouseEvent(MOUSEEVENTF_LEFTDOWN);
								rei();
							}
							else
								connect(out);
							break;
						case 'r':
							if (qqb(L"<lr>")) { //left release
								mouseEvent(MOUSEEVENTF_LEFTUP);
								rei();
							}
							else
								connect(out);
							break;
						case 'e':
							if (qqb(L"<left"))
								kb_press(L"<left", VK_LEFT);
							else
								connect(out);
							break;
						case 's':
							if (qqb(L"<ls"))
								kb_press(L"<ls", VK_F7); //hscroll+
							else
								connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'm':
						switch (qq[2]) {
						case 'l':
							if (qqb(L"<ml>")) {//print multiLineDelimiter
								wstring w = repeats;
								run(utf8_to_wstring(delimiter), vdb, 1);
								repeats = w;
								rei();
								if (out_speed > 0) out_sleep = 0;
							}
							else connect(out);
							break;
						case 'c':
							if (qqb(L"<mc")) kb_press(L"<mc", VK_F7);//middle click
							else connect(out);
							break;
						case 'h':
							if (qqb(L"<mh>")) {//middle hold
								mouseEvent(MOUSEEVENTF_MIDDLEDOWN);
								rei();
							}
							else connect(out);
							break;
						case 'r':
							if (qqb(L"<mr>")) {//middle release
								mouseEvent(MOUSEEVENTF_MIDDLEUP);
								rei();
							}
							else connect(out);
							break;
						case 'e':
							if (qqb(L"<menu")) kb_press(L"<menu", VK_APPS);
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'p':
						switch (qq[2]) {
						case 'a':
							if (qqb(L"<pause")) { kb_press(L"<pause", VK_PAUSE); GetAsyncKeyState(VK_PAUSE); }
							else connect(out);
							break;
						case 's':
							if (qqb(L"<ps")) kb_press(L"<ps", VK_SNAPSHOT);
							else connect(out);
							break;
						case 'u':
							if (qqb(L"<pu")) kb_press(L"<pu", VK_PRIOR);//pgup
							else connect(out);
							break;
						case 'd':
							if (qqb(L"<pd")) kb_press(L"<pd", VK_NEXT);//pgdn
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case'R':
					case'r':
						switch (qq[2]) {
						case ':':
							if (testqqb(L"<R:") || testqqb(L"<r:")) {//.h ReplacerDb:
								if (qq[1] == 'R') { showOutsMsg(L"", qp, L"", 0); }
								qp = regex_replace(qp, wregex(L"/"), L"\\");
								replacerDb = qp;
								rei();
							}
							else connect(out);
							break;
						case 'c':
							if (qqb(L"<rc")) kb_press(L"<rc", VK_F7); else connect(out);
							break;
						case 'h':
							if (qqb(L"<rh>")) {//right hold
								mouseEvent(MOUSEEVENTF_RIGHTDOWN);
								rei();
							}
							else connect(out);
							break;
						case 'r':
							if (qqb(L"<rr>")) {//right release
								mouseEvent(MOUSEEVENTF_RIGHTUP);
								rei();
							}
							else connect(out);
							break;
						case 'i':
							if (qqb(L"<right")) kb_press(L"<right", VK_RIGHT); else connect(out);
							break;
						case 's':
							if (qqb(L"<rs")) { kb_press(L"<rs", VK_F7); }
							else connect(out);//hscroll-
							break;
						case 'G':
						case 'g':
							if (qqb(L"<rgb")) {//print r g b
								if (qq[4] == ':' && qq[5] == '>') { rei(); connect(out); }
								out = getRGB(qq[4] == '>' ? 8 : 1);
								if (out[0]) c = -1;
								if (out_speed > 0) out_sleep = 0;

							}
							else connect(out);
							break;
						case 'e':
							if (testqqb(L"<replace:")) {
								if (cbGet() > L"") {
									if (qp.find(L"\\,") != wstring::npos) {// \,
										wstring t = qp.substr(qp.find_last_of(L"\\") + 2);
										if (t.find(',') != string::npos) {
											qx = qp.substr(0, qp.find_last_of(L"\\") + t.find(',') + 2);
											qy = qp.substr(qx.length() + 1);
											qx = regex_replace(qx, wregex(L"\\\\,"), L",");// \,
										}
									}
									wstring d = utf8_to_wstring(delimiter);
									qx = regex_replace(qx, wregex(L"\\\\g"), L">"); qx = regex_replace(qx, wregex(L"\\\\m"), d);
									qy = regex_replace(qy, wregex(L"\\\\g"), L">"); qy = regex_replace(qy, wregex(L"\\\\m"), d);
									wstring b = regex_replace(cbGet(), wregex(qx), qy);
									cbSet(b);
								}
								rei();
							}
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case's':
					case'S':
						switch (qq[2]) {
						case 'E':
						case 'e':
							if (testqqb(L"<SE:") || testqqb(L"<se:")) {//.h Switch Settings: file
								if (qq[1] == 'S') showOutsMsg(L"", qp, L"", 0);
								qp = regex_replace(qp, wregex(L"/"), L"\\");
								wifstream f(qp); if (!f) { showOutsMsg(L"", L"\\n\\4Settings \\7\\0C\\" + qp + L"\\0C\\\\4 not found!\\7", L"", 1); return; }
								settings = qp;
								se = settings.substr(settings.find_last_of('\\') + 1) + L" - ";
								wstring db_ = database;
								load_settings();
								if (db_ != database) {
									mvdb = 1;
									vstrand.clear();
									vstrand = make_vdb_table();
								}
								rei();
								break;
							}
							else if (qqb(L"<se>") || qqb(L"<SE>")) { printSe(); rei(); }
							else connect(out);
							break;
						case 'h':
							if (qqb(L"<shift>")) { kb_hold(VK_LSHIFT); rei(); }
							else if (qqb(L"<shift->")) { kb_release(VK_LSHIFT); kb_release(VK_RSHIFT); rei(); }
							else if (qqb(L"<shift")) kb_press(L"<shift", VK_LSHIFT);
							else connect(out);
							break;
						case 'p':
							if (testqqb(L"<speed:")) {
								if (check_if_num(qp, L"<speed: {slot}>") != L"") {
									wstring n = qp;
									if (n[0] == ' ') n = n.substr(1);
									//if (n[0] == '<' && n.substr(1, 5) == L"rand:") {//<speed: <rand: 0, 1111>>
									//	setQxQy(n, 6);
									//	c += 1;
									//	n = randn(1);
									//	if (n == L"0") { c += qq.find('>'); return; }
									//}
									out_speed = stoi(n); rei(); out_sleep = 0;
								}
								else printq();
							}
							else if (qqb(L"<space")) kb_press(L"<space", VK_SPACE);
							else connect(out);
							break;
						case 'd':
							if (qqb(L"<sd")) { kb_press(L"<sd", VK_F7); }//scroll down
							else connect(out);
							break;
						case 'r':
							if (qqb(L"<sr")) { kb_press(L"<sr", VK_F7); }//scroll right
							else connect(out);
							break;
						case 'u':
							if (qqb(L"<su")) { kb_press(L"<su", VK_F7); }//scroll up
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case't':
						if (qqb(L"<tab")) kb_press(L"<tab", VK_TAB);
						else if (qqb(L"<time>") || qqb(L"<time:>")) {
							wstring w{}; getTime(w);
							if (qq[5] == '>') w = w.substr(w.rfind(L" ") - 8, 8);
							out = w + qq.substr(qq.find('>') + 1, qq.length());
							c = -1;
							if (out_speed > 0) out_sleep = 0;
						}
						else connect(out);
						break;
					case'u':
						if (qqb(L"<upper>")) { wstring s = L"", c = L""; c = cbGet(); for (size_t x = 0; x < c.length(); x++) { s += toupper(c[x]); } cbSet(s); rei(); }
						else if (qqb(L"<up")) kb_press(L"<up", VK_UP);
						else connect(out);
						break;
					case 'v':
						if (qqb(L"<v>")) { toggle_visibility(); rei(); }
						else connect(out);
						break;
					case'w':
						if (qqb(L"<win>")) { kb_hold(VK_LWIN); rei(); }
						else if (qqb(L"<win->")) { kb_release(VK_LWIN); rei(); }
						else if (qqb(L"<win")) kb_press(L"<win", VK_LWIN);
						else connect(out);
						break;
					case'X':
					case'x':
						switch (qq[2]) {
						case 'y':
							if (testqqb(L"<xy:") || testqqb(L"<xy~:")) {
								if (delimiter[0] != '\n' && qx[0] == '\n' || qx[0] == '\t' || qy[0] == '\n' || qy[0] == '\t') {
									qx = regex_replace(qx, wregex(L"\n"), L""); qx = regex_replace(qx, wregex(L"\t"), L"");
									qy = regex_replace(qy, wregex(L"\n"), L""); qy = regex_replace(qy, wregex(L"\t"), L"");
								}
								if (qx[0] == '.' || qy[0] == '.' || qq[3] == '~') {//Use . for current pt | <xy:. 0>  <t-<ifxy:0 . | . 0 | . 864 | 1638 .,1,1000,:>1
									POINT pt; GetCursorPos(&pt);
									if (qq[3] == '~') { qxcc = pt.x; qycc = pt.y; } //for <~~>
									else { qx == L"." ? qx = to_wstring(pt.x) : qy = to_wstring(pt.y); }
								}
								SetCursorPos(stoi(qx), stoi(qy)); rei();
							}
							else if (qqb(L"<xy>")) {//print pointer
								POINT pt; GetCursorPos(&pt);
								out = to_wstring(pt.x) + L" " + to_wstring(pt.y) + qq.substr(qq.find('>') + 1, qq.length());
								c = -1;
								if (out_speed > 0) out_sleep = 0;
							}
							else connect(out);
							break;
						default:
							connect(out);
						}
						break;
					case 'y':
						if (testqqb(L"<yesno:")) {

							wstring me = qp;

							if (npos_find(qp, '\\', 1)) {
								me = regex_replace(me, wregex(L"[\\\\][\\s]"), L"::s::");
							}

							auto qu = me.substr(0, me.find(' '));
							me = me.substr(me.find(' ') + 1);

							if (npos_find(qp, '\\', 1)) {
								me = regex_replace(me, wregex(L"::s::"), L" ");
								me = regex_replace(me, wregex(L"\\\\g"), L">");
								me = regex_replace(me, wregex(L"\\\\n"), L"\n");
								qu = regex_replace(qu, wregex(L"::s::"), L" ");
								qu = regex_replace(qu, wregex(L"\\\\g"), L">");
								qu = regex_replace(qu, wregex(L"\\\\n"), L"\n");
							}

							int m = MessageBoxW(0, me.c_str()
								, qu.c_str()
								, MB_YESNO);
							if (m == IDYES) {
								rei();
								continue;
							}
							else {
								c = out.length();
								break;
							}
						}
						else connect(out);
						break;
					default:
						connect(out);
					} //<x>
					break;
				default: {
					if ((out[c] > 32 && out[c] < 39) || (out[c] > 39 && out[c] < 44) || out[c] == 58 || (out[c] > 61 && out[c] < 91) || out[c] == 94 || out[c] == 95 || (out[c] > 122 && out[c] < 127))
						hold_shift = true; //if !"#$%& ()*+ : > ?&AZ ^ _ {|}~

					if (hold_shift)
						kb_hold(VK_LSHIFT);

					kb(out[c]);

					if (hold_shift)
						shift_release();

					clear_key(out[c]);

				}

				}

			}

			if (debug == 1) {
				wcout << "\ninput: " << in << endl;
				wcout << "output: " << out << endl;
			}

			if (multi_.store_[0]) repeats = multi_.store_;

			break;
		}

	}

	out_speed = 0;
	if (RSHIFTLSHIFT_Only) rri = 0;
	if (found_io || strand[0] && strand[strand.length() - 1] == '>') {
		if (ccm) { close_ctrl_mode = !close_ctrl_mode; ccm = 0; }
		if (strand[0]) strand.clear();
		prints();
		stop = 0;
	}
}

static void repeat_out(wstring ai, vector<Strand> const& vdb) {
	repeats = L">" + ai;
	if (repeats != L">")
		scan_db(vdb);
}

static void repeat(vector<Strand> const& vdb) {
	switch (repeat_switch) {
	case 0: {
		if (strand[0]) strand.clear();
		thread thread(repeat_out, repeats, cref(vdb));
		thread.detach();
		break;
	}
	case 1: //esc + p
		printq();
		run(L"xy~:", vdb, 1);
		run(getXY(), vdb, 1);
		break;

	case 2: //esc + r
		printq();
		run(getRGB(), vdb, 1);
		break;

	case 3: //esc + g
		qq.clear();
		getRGB(1);
		break;
	
	case 4: //esc + a
		sleep(frequency / 2);
		run(L"<alt><esc><alt->", vdb, 1);
		wstring t = getAppT();
		run(L"<,><shift><alt><esc><alt-><shift->", vdb, 1);
		printq();
		run(L"ifapp~:" + t + (Loop_Insert_Text > L"" ? Loop_Insert_Text : L">"), vdb, 1);
		repeat_switch = 4;
		break;
	}
}

static void run(wstring w, vector<Strand> const& vdb, bool clear = 1) {
	repeats = L">" + w;
	scan_db(vdb);
	strand.clear();
	if (clear) repeats.clear();
}

static void scan(vector<Strand> const& vdb) {
	scan_db(cref(vdb));
}

static void key(wstring k, vector<Strand> const& vdb) {

	if (k[0] == '>') { //Kb_Key_F2 = ">"
		if (!strand[0]) k[0] = '<';
		else if (strand[0] != '<' && strand.length() > 0 || strand.length() > 1)
			k = '>';
		else {
			strand.clear();
			prints();
			return;
		}
	}

	strand.append(k);

	if (k[0] == '>' || !close_ctrl_mode) {
		//scan_db(vdb);
		if (k[0] == '>') prints();
		thread thread(scan, cref(vdb)); thread.detach();
		if (k[0] == '>') clear_all_keys();
		if (close_ctrl_mode) return;
	}

	if (strand_length && strand[0] != '<' && k[0] != '>') {
		if (strand.length() > strand_length && !utf_8)
			strand = strand.substr(1);
		else if(utf_8) {
			size_t x = 0;
			for (size_t i = 0; i < strand.length(); ++i) {
				if (strand[i] > 127) {
					++x; ++i;
				}
				else ++x;
			}
			if(x > strand_length)
				strand = strand[0] < 127 ? strand.substr(1) : strand.substr(2);
		}
	}

	if (k[0] != '>')
		prints();
}

#pragma endregion

#pragma comment(lib, "Winmm.lib")//<audio:>

int main() {
	{
		GetAsyncKeyState(VK_ESCAPE);
		for (size_t i = 0; i <= 1; ++i) {
			if (GetAsyncKeyState(VK_ESCAPE)) break;
			WCHAR t[MAX_PATH];
			GetSystemDirectoryW(t, MAX_PATH);
			wstring c = L"";
			for (i = 0; ; ++i) {
				if (t[i] == ':') {
					c += L":\\anu";
					break;
				}
				c += t[i];
			} //root dir
			database = c + L"\\db.txt";
			settings = c + L"\\se.txt";
			replacerDb = database;
			if (CreateDirectoryW(c.c_str(), NULL)) { //L"c:\anu"
				wstring db_ = L"";
				wstring se_ = L"";
				wcout << database << " not found.\n[1] auto create \n(delete c:\\anu to reset)\n\n";
				bool num = 0;
				for (;; sleep(frequency)) {
					GetAsyncKeyState(VK_ESCAPE); if (GetAsyncKeyState(VK_ESCAPE)) { RemoveDirectoryW(c.c_str()); break; }
					if (GetAsyncKeyState('1') || GetAsyncKeyState(VK_NUMPAD1)) { num = 1; break; }
				}
				if (num) {
					db_ = LR"(<anu><'\012\                                          __   .__  \n_____    ____  __ __  ____   ____ _____  |  | _|__| \n\__  \  /    \|  |  \/    \ /    \\__   \ |  |/ /  | \n / __ \|   |  \  |  /   |  \   |  \/ __ \|    <|  | \n(____  /___|  /____/|___|  /___|  (____  /__|_ \__| \n     \/     \/           \/     \/     \/     \/    \7><'\nWELCOME! [\T] [\012\?+ESC\W]><db >

db
<db ><wr:>c:\anu\db.txt<enter>

<wr:><win>r<win-><ifapp~:run,6,9>

se
<se ><se>)";
					se_ = LR"(StartHidden				0
ShowInput				1
InputLength				2
Ignore_F1-F12			0
Kb_Key_F2				>
CtrlKey					163 9
RSHIFT+LSHIFT_Only		0
RSHIFT+CtrlKey_Toggle	9
RgbScaleLayout			1.00
)";

					wofstream fd(database); fd << db_; fd.close();
					wofstream fs(settings); fs << se_; fs.close();
				}
			}
		}
	}

	load_settings();

	if (start_hidden)ShowWindow(GetConsoleWindow(), SW_HIDE);

	SetConsoleOutputCP(CP_UTF8);

	if (utf_8)
		wcout.imbue(locale(wcout.getloc(), new codecvt_utf8_utf16<wchar_t>));

	delimiter = wstring_to_utf8(w_delimiter);

	if (delimiter[0] != '\n' && delimiter[0] > 127)
		delimiter = delimiter.substr(1);

	strand = L"<anu>";

	auto vdb = make_vdb_table();

	scan_db(vdb);

	repeats = repeats[0] ? L"<anu:>" + repeats.substr(5) : L"";

	strand.clear();

	for (;; this_thread::sleep_for(chrono::milliseconds(frequency))) {

		if (GetAsyncKeyState(VK_BACK)) {
			if (!strand[0]) { if (rri) rri = 0; continue; }

			if (utf_8 && strand[strand.length() - 1] > 127) {
				strand = strand.substr(0, strand.length() - 2);
			}
			else
				strand = strand.substr(0, strand.length() - 1);
			prints();
			continue;
		}

		if (GetAsyncKeyState(VK_RSHIFT)) {
			unsigned short min = 0; bool ex = 0;
			while (GetAsyncKeyState(VK_RSHIFT) != 0) {
				if (GetAsyncKeyState(VK_LSHIFT)) { //RSHIFT+LSHIFT <
					++rri; unsigned short x = 0;
					while (GetAsyncKeyState(VK_RSHIFT) != 0) {
						if (GetAsyncKeyState(VK_LSHIFT))
							++x;
						while (GetAsyncKeyState(VK_LSHIFT) != 0)
							sleep(frequency / 4);
						sleep(1);
					}
					if (x > 1) strand = x == 2 ? L"<" : L"";
					else if (strand[0] && strand != L"<") { key(L">", vdb); ex = 1; break; }
					else if (!strand[0]) { strand = RSHIFTLSHIFT_Only > 1 && rri == 1 ? L"" : L"<"; }
					else if (RSHIFTLSHIFT_Only > 1) strand = L"";
					else strand = strand[0] == '<' ? L"" : L"<";
					prints(); clear_all_keys(); break;
				}
				if (GetAsyncKeyState(cKey) && RSHIFTCtrlKeyToggle) { //rshift + cKey
					if (min > RSHIFTCtrlKeyToggle) { ex = 1; break; }
					if (cKey == VK_SPACE) { kb(VK_BACK); GetAsyncKeyState(VK_BACK); }
					close_ctrl_mode = !close_ctrl_mode;
					ccm = !ccm;
					ex = 1; break;
				}
				++min;
				sleep(frequency / 4);
			}
			if (ex) continue;
			clear_all_keys();
			continue;
		}

		if (GetAsyncKeyState(VK_LSHIFT)) {
			bool ex = 0; while (GetAsyncKeyState(VK_LSHIFT) != 0) {
				if (LSHIFTCtrlKey) {
					short min = 0; while (GetAsyncKeyState(VK_LSHIFT) != 0) {
						++min;
						if (GetAsyncKeyState(cKey)) { //lshift + ctrlKey
							if (min > LSHIFTCtrlKey) { sleep(frequency / 4); continue; }
							if (cKey == VK_SPACE) { kb(VK_BACK); GetAsyncKeyState(VK_BACK); }
							clear_all_keys();
							strand = strand[0] == '<' ? L"<" : L"";
							prints();
							rri = 1;
							while (GetAsyncKeyState(cKey) != 0) sleep(frequency / 4);
							kb_release(VK_LSHIFT);
							ex = 1; break;
						}
						if (GetAsyncKeyState(VK_ESCAPE)) break;
						sleep(frequency / 4);
					}
				}
				if (ex) break;
				sleep(frequency / 4);
			}
			if (ex) continue;
			clear_all_keys();
			continue;
		}

		if (GetAsyncKeyState(VK_LCONTROL)) {
			GetAsyncKeyState(83); bool ex = 0;
			while (GetAsyncKeyState(VK_LCONTROL) != 0) {
				while (GetAsyncKeyState(VK_LCONTROL) != 0) {
					if (GetAsyncKeyState(83)) {
						while (GetAsyncKeyState(83) != 0)
							sleep(frequency / 3);
						if (FindWindowW(0, (editorSe).c_str()) == GetForegroundWindow() || FindWindowW(0, (se + editor).c_str()) == GetForegroundWindow()) {
							load_settings(); strand.clear(); prints();
						}
						else if (FindWindowW(0, (editorDb).c_str()) == GetForegroundWindow() || FindWindowW(0, (db + editor).c_str()) == GetForegroundWindow()) {
							vstrand.clear(); vdb = make_vdb_table(); strand.clear(); prints();
						}
						while (GetAsyncKeyState(VK_CONTROL) != 0) sleep(frequency / 3);
						ex = 1; break;
					}//lctrl+s
					sleep(frequency / 4);
				}
				if (ex) break;
				sleep(frequency / 4);
			}
			clear_all_keys();
			if (ex) continue;
			continue;
		}

		if (GetAsyncKeyState(cKey) && cKeyMax) {//toggle <
			unsigned short x = 0, min = 0;
			while (GetAsyncKeyState(cKey) != 0) {
				if (GetAsyncKeyState(VK_LCONTROL)) {
					while (GetAsyncKeyState(VK_LCONTROL) != 0) sleep(1);
					++x;
				}
				++min;
				sleep(frequency / 4);
			}
			if (x) { //cKey + lctrl
				if (GetAsyncKeyState(VK_ESCAPE)) continue;
				//wstring r = L""; for (unsigned char i = 0; i < x; ++i) r += out;
				//run(r, 0);
				repeat(vdb);
				continue;
			}
			if (RSHIFTLSHIFT_Only && !strand[0] && !rri) continue;
			if (min > cKeyMax) {}
			else {
				if (cKey == VK_SPACE) { kb(VK_BACK); GetAsyncKeyState(VK_BACK); }
				if (!strand[0]) strand = L"<";
				else {
					if (strand[0] && strand != L"<") { key(L">", vdb); continue; }
					if (RSHIFTLSHIFT_Only > 1) strand = L"";
					else strand = strand[0] == '<' ? L"" : L"<";
				}
				prints();
			}
			clear_all_keys();
			continue;
		}

		if (GetAsyncKeyState(repeat_key)) {
			//while (GetAsyncKeyState(repeat_key) != 0) 
			//	sleep(frequency / 4);
			if (auto_bs_repeat_key) {
				kb(VK_BACK); GetAsyncKeyState(VK_BACK);
			}
			repeat(vdb);
			continue;
		}

		if (GetAsyncKeyState(clear_strand_key)) {
			if (!strand[0] || strand == L"<") continue;
			clear_all_keys();
			strand = strand[0] == '<' ? L"<" : L"";
			prints();
			continue;
		}

		if (GetAsyncKeyState(VK_ESCAPE)) {
			GetAsyncKeyState('P'); if (GetAsyncKeyState('P')) { //p + esc: <xy:>
				kb_release(VK_ESCAPE); kb(VK_BACK); GetAsyncKeyState(VK_BACK);
				repeat_switch = 1;
				repeat(vdb);
				continue;
			}
			GetAsyncKeyState('R'); if (GetAsyncKeyState('R')) { //r + esc: <rgb:>
				kb_release(VK_ESCAPE); kb(VK_BACK); GetAsyncKeyState(VK_BACK);
				repeat_switch = 2;
				repeat(vdb);
				continue;
			}
			GetAsyncKeyState('G'); if (GetAsyncKeyState('G')) { //g + esc: <RGB~:> to cb
				kb_release(VK_ESCAPE); kb(VK_BACK); GetAsyncKeyState(VK_BACK);
				repeat_switch = 3;
				repeat(vdb);
				continue;
			}
			GetAsyncKeyState('A'); if (GetAsyncKeyState('A')) { //a + esc: <app:>
				kb_release(VK_ESCAPE); kb(VK_BACK); GetAsyncKeyState(VK_BACK);
				repeat_switch = 4;
				repeat(vdb);
				continue;
			}
			GetAsyncKeyState(VK_OEM_PLUS); if (GetAsyncKeyState(VK_OEM_PLUS)) { //= + esc: repeat
				kb_release(VK_ESCAPE); kb(VK_BACK); GetAsyncKeyState(VK_BACK);
				repeat(vdb); continue;
			}
			GetAsyncKeyState(VK_OEM_COMMA); if (GetAsyncKeyState(VK_OEM_COMMA)) { //, + esc
				unsigned short x = 0;
				while (GetAsyncKeyState(VK_OEM_COMMA) != 0) {
					if (GetAsyncKeyState(VK_ESCAPE)) {
						if (!x) { kb(VK_BACK); GetAsyncKeyState(VK_BACK); } //, + esc (esc)
						++x;
					}
					while (GetAsyncKeyState(VK_ESCAPE) != 0)
						sleep(1);

					sleep(1);
				}
				if (RSHIFTLSHIFT_Only) ++rri;
				if (x > 1) strand = x == 2 ? L"<" : L"";
				else if (strand[0] && strand != L"<") { key(L">", vdb); continue; }
				else if (!strand[0]) { strand = (RSHIFTLSHIFT_Only > 1 && rri == 1) ? L"" : L"<"; }
				else if (RSHIFTLSHIFT_Only > 1) strand = L"";
				else strand = strand[0] == '<' ? L"" : L"<";
				prints(); clear_all_keys();
				continue;
			}
			GetAsyncKeyState('L'); if (GetAsyncKeyState('L')) { //L + esc
				kb(VK_BACK); GetAsyncKeyState(VK_BACK);
				static unsigned short escL = RSHIFTLSHIFT_Only;
				if (RSHIFTLSHIFT_Only) RSHIFTLSHIFT_Only = 0;
				else RSHIFTLSHIFT_Only = escL ? escL : 2;
				strand.clear(); clear_all_keys(); prints();
				sleep(frequency);
				continue;
			}
			GetAsyncKeyState('X'); if (GetAsyncKeyState('X')) { //x + esc
				kb(VK_BACK); return 0;
			}
			GetAsyncKeyState('H'); if (GetAsyncKeyState('H')) { //h + esc
				kb_release(VK_ESCAPE); kb(VK_BACK); GetAsyncKeyState(VK_BACK);
				sleep(1);
				toggle_visibility();
				prints();
				continue;
			}
			GetAsyncKeyState(VK_OEM_2); if (GetAsyncKeyState(VK_OEM_2)) { //? + esc
				kb_release(VK_ESCAPE); kb(VK_BACK); GetAsyncKeyState(VK_BACK);
				print_ctrls();
				ShowWindow(GetConsoleWindow(), SW_RESTORE);
				SetForegroundWindow(GetConsoleWindow());
				continue;
			}
			if (Kb_Key_Esc[0]) { kb_release(VK_ESCAPE); key(Kb_Key_Esc, vdb); }
			continue;
		}

		if (ctrl_scan_only_mode && strand[0] != '<') continue;

		if (!rri && RSHIFTLSHIFT_Only && !strand[0]) continue;

#pragma region input_strand
		if (!ignoreAZ) {
			if (Kb_Key_A[0] && GetAsyncKeyState(0x41)/* & 0x8000*/) { key(Kb_Key_A, vdb); continue; }
			if (Kb_Key_B[0] && GetAsyncKeyState(0x42)) { key(Kb_Key_B, vdb); continue; }
			if (Kb_Key_C[0] && GetAsyncKeyState(0x43)) { key(Kb_Key_C, vdb); continue; }
			if (Kb_Key_D[0] && GetAsyncKeyState(0x44)) { key(Kb_Key_D, vdb); continue; }
			if (Kb_Key_E[0] && GetAsyncKeyState(0x45)) { key(Kb_Key_E, vdb); continue; }
			if (Kb_Key_F[0] && GetAsyncKeyState(0x46)) { key(Kb_Key_F, vdb); continue; }
			if (Kb_Key_G[0] && GetAsyncKeyState(0x47)) { key(Kb_Key_G, vdb); continue; }
			if (Kb_Key_H[0] && GetAsyncKeyState(0x48)) { key(Kb_Key_H, vdb); continue; }
			if (Kb_Key_I[0] && GetAsyncKeyState(0x49)) { key(Kb_Key_I, vdb); continue; }
			if (Kb_Key_J[0] && GetAsyncKeyState(0x4A)) { key(Kb_Key_J, vdb); continue; }
			if (Kb_Key_K[0] && GetAsyncKeyState(0x4B)) { key(Kb_Key_K, vdb); continue; }
			if (Kb_Key_L[0] && GetAsyncKeyState(0x4C)) { key(Kb_Key_L, vdb); continue; }
			if (Kb_Key_M[0] && GetAsyncKeyState(0x4D)) { key(Kb_Key_M, vdb); continue; }
			if (Kb_Key_N[0] && GetAsyncKeyState(0x4E)) { key(Kb_Key_N, vdb); continue; }
			if (Kb_Key_O[0] && GetAsyncKeyState(0x4F)) { key(Kb_Key_O, vdb); continue; }
			if (Kb_Key_P[0] && GetAsyncKeyState(0x50)) { key(Kb_Key_P, vdb); continue; }
			if (Kb_Key_Q[0] && GetAsyncKeyState(0x51)) { key(Kb_Key_Q, vdb); continue; }
			if (Kb_Key_R[0] && GetAsyncKeyState(0x52)) { key(Kb_Key_R, vdb); continue; }
			if (Kb_Key_S[0] && GetAsyncKeyState(0x53)) { key(Kb_Key_S, vdb); continue; }
			if (Kb_Key_T[0] && GetAsyncKeyState(0x54)) { key(Kb_Key_T, vdb); continue; }
			if (Kb_Key_U[0] && GetAsyncKeyState(0x55)) { key(Kb_Key_U, vdb); continue; }
			if (Kb_Key_V[0] && GetAsyncKeyState(0x56)) { key(Kb_Key_V, vdb); continue; }
			if (Kb_Key_W[0] && GetAsyncKeyState(0x57)) { key(Kb_Key_W, vdb); continue; }
			if (Kb_Key_X[0] && GetAsyncKeyState(0x58)) { key(Kb_Key_X, vdb); continue; }
			if (Kb_Key_Y[0] && GetAsyncKeyState(0x59)) { key(Kb_Key_Y, vdb); continue; }
			if (Kb_Key_Z[0] && GetAsyncKeyState(0x5A)) { key(Kb_Key_Z, vdb); continue; }
		}
		if (!ignore09) {
			if (Kb_Key_0[0] && GetAsyncKeyState(0x30)) { key(Kb_Key_0, vdb); continue; }
			if (Kb_Key_1[0] && GetAsyncKeyState(0x31)) { key(Kb_Key_1, vdb); continue; }
			if (Kb_Key_2[0] && GetAsyncKeyState(0x32)) { key(Kb_Key_2, vdb); continue; }
			if (Kb_Key_3[0] && GetAsyncKeyState(0x33)) { key(Kb_Key_3, vdb); continue; }
			if (Kb_Key_4[0] && GetAsyncKeyState(0x34)) { key(Kb_Key_4, vdb); continue; }
			if (Kb_Key_5[0] && GetAsyncKeyState(0x35)) { key(Kb_Key_5, vdb); continue; }
			if (Kb_Key_6[0] && GetAsyncKeyState(0x36)) { key(Kb_Key_6, vdb); continue; }
			if (Kb_Key_7[0] && GetAsyncKeyState(0x37)) { key(Kb_Key_7, vdb); continue; }
			if (Kb_Key_8[0] && GetAsyncKeyState(0x38)) { key(Kb_Key_8, vdb); continue; }
			if (Kb_Key_9[0] && GetAsyncKeyState(0x39)) { key(Kb_Key_9, vdb); continue; }
		}
		if (!ignoreF1s) {
			if (Kb_Key_F1[0] && GetAsyncKeyState(0x70)) { key(Kb_Key_F1, vdb); continue; }
			if (Kb_Key_F2[0] && GetAsyncKeyState(0x71)) { key(Kb_Key_F2, vdb); continue; }
			if (Kb_Key_F3[0] && GetAsyncKeyState(0x72)) { key(Kb_Key_F3, vdb); continue; }
			if (Kb_Key_F4[0] && GetAsyncKeyState(0x73)) { key(Kb_Key_F4, vdb); continue; }
			if (Kb_Key_F5[0] && GetAsyncKeyState(0x74)) { key(Kb_Key_F5, vdb); continue; }
			if (Kb_Key_F6[0] && GetAsyncKeyState(0x75)) { key(Kb_Key_F6, vdb); continue; }
			if (Kb_Key_F7[0] && GetAsyncKeyState(0x76)) { key(Kb_Key_F7, vdb); continue; }
			if (Kb_Key_F8[0] && GetAsyncKeyState(0x77)) { key(Kb_Key_F8, vdb); continue; }
			if (Kb_Key_F9[0] && GetAsyncKeyState(0x78)) { key(Kb_Key_F9, vdb); continue; }
			if (Kb_Key_F10[0] && GetAsyncKeyState(0x79)) { key(Kb_Key_F10, vdb); continue; }
			if (Kb_Key_F11[0] && GetAsyncKeyState(0x7A)) { key(Kb_Key_F11, vdb); continue; }
			if (Kb_Key_F12[0] && GetAsyncKeyState(0x7B)) { key(Kb_Key_F12, vdb); continue; }
		}
		if (!ignoreArrows) {
			if (Kb_Key_Left[0] && GetAsyncKeyState(VK_LEFT)) { key(Kb_Key_Left, vdb); continue; }
			if (Kb_Key_Up[0] && GetAsyncKeyState(VK_UP)) { key(Kb_Key_Up, vdb); continue; }
			if (Kb_Key_Right[0] && GetAsyncKeyState(VK_RIGHT)) { key(Kb_Key_Right, vdb); continue; }
			if (Kb_Key_Down[0] && GetAsyncKeyState(VK_DOWN)) { key(Kb_Key_Down, vdb); continue; }
		}
		if (!ignoreOtherKeys) {
			if (Kb_Key_Print_Screen[0] && GetAsyncKeyState(VK_SNAPSHOT)) { key(Kb_Key_Print_Screen, vdb); continue; }
			if (Kb_Key_Space[0] && GetAsyncKeyState(VK_SPACE)) { key(Kb_Key_Space, vdb); continue; }
			if (Kb_Key_Tab[0] && GetAsyncKeyState(VK_TAB)) { key(Kb_Key_Tab, vdb); continue; }
			if (Kb_Key_Left_Shift[0] && GetAsyncKeyState(VK_LSHIFT)) { key(Kb_Key_Left_Shift, vdb); continue; }
			if (Kb_Key_Right_Shift[0] && GetAsyncKeyState(VK_RSHIFT)) { key(Kb_Key_Right_Shift, vdb); continue; }
			if (Kb_Key_Left_Ctrl[0] && GetAsyncKeyState(VK_LCONTROL)) { key(Kb_Key_Left_Ctrl, vdb); continue; }
			if (Kb_Key_Right_Ctrl[0] && GetAsyncKeyState(VK_RCONTROL)) { key(Kb_Key_Right_Ctrl, vdb); continue; }
			if (Kb_Key_Enter[0] && GetAsyncKeyState(VK_RETURN)) { key(Kb_Key_Enter, vdb); continue; }
			if (Kb_Key_Caps[0] && GetAsyncKeyState(VK_CAPITAL)) { key(Kb_Key_Caps, vdb); continue; }
			if (Kb_Key_Grave_Accent[0] && GetAsyncKeyState(VK_OEM_3)) { key(Kb_Key_Grave_Accent, vdb); continue; }
			if (Kb_Key_Minus[0] && GetAsyncKeyState(VK_OEM_MINUS)) { key(Kb_Key_Minus, vdb); continue; }
			if (Kb_Key_Equal[0] && GetAsyncKeyState(VK_OEM_PLUS)) { key(Kb_Key_Equal, vdb); continue; }
			if (Kb_Key_Left_Bracket[0] && GetAsyncKeyState(VK_OEM_4)) { key(Kb_Key_Left_Bracket, vdb); continue; }
			if (Kb_Key_Right_Bracket[0] && GetAsyncKeyState(VK_OEM_6)) { key(Kb_Key_Right_Bracket, vdb); continue; }
			if (Kb_Key_Backslash[0] && GetAsyncKeyState(VK_OEM_5)) { key(Kb_Key_Backslash, vdb); continue; }
			if (Kb_Key_Semicolon[0] && GetAsyncKeyState(VK_OEM_1)) { key(Kb_Key_Semicolon, vdb); continue; }
			if (Kb_Key_Quote[0] && GetAsyncKeyState(VK_OEM_7)) { key(Kb_Key_Quote, vdb); continue; }
			if (Kb_Key_Comma[0] && GetAsyncKeyState(VK_OEM_COMMA)) { key(Kb_Key_Comma, vdb); continue; }
			if (Kb_Key_Period[0] && GetAsyncKeyState(VK_OEM_PERIOD)) { key(Kb_Key_Period, vdb); continue; }
			if (Kb_Key_Forwardslash[0] && GetAsyncKeyState(VK_OEM_2)) { key(Kb_Key_Forwardslash, vdb); continue; }
			if (Kb_Key_Menu[0] && GetAsyncKeyState(VK_APPS)) { key(Kb_Key_Menu, vdb); continue; }
			if (Kb_Key_Insert[0] && GetAsyncKeyState(VK_INSERT)) { key(Kb_Key_Insert, vdb); continue; }
			if (Kb_Key_Delete[0] && GetAsyncKeyState(VK_DELETE)) { key(Kb_Key_Delete, vdb); continue; }
			if (Kb_Key_Home[0] && GetAsyncKeyState(VK_HOME)) { key(Kb_Key_Home, vdb); continue; }
			if (Kb_Key_End[0] && GetAsyncKeyState(VK_END)) { key(Kb_Key_End, vdb); continue; }
			if (Kb_Key_PgUp[0] && GetAsyncKeyState(VK_PRIOR)) { key(Kb_Key_PgUp, vdb); continue; }
			if (Kb_Key_PgDn[0] && GetAsyncKeyState(VK_NEXT)) { key(Kb_Key_PgDn, vdb); continue; }
		}
		if (!ignoreNumPad) {
			if (Kb_Key_Numpad_0[0] && GetAsyncKeyState(VK_NUMPAD0)) { key(Kb_Key_Numpad_0, vdb); continue; }
			if (Kb_Key_Numpad_1[0] && GetAsyncKeyState(VK_NUMPAD1)) { key(Kb_Key_Numpad_1, vdb); continue; }
			if (Kb_Key_Numpad_2[0] && GetAsyncKeyState(VK_NUMPAD2)) { key(Kb_Key_Numpad_2, vdb); continue; }
			if (Kb_Key_Numpad_3[0] && GetAsyncKeyState(VK_NUMPAD3)) { key(Kb_Key_Numpad_3, vdb); continue; }
			if (Kb_Key_Numpad_4[0] && GetAsyncKeyState(VK_NUMPAD4)) { key(Kb_Key_Numpad_4, vdb); continue; }
			if (Kb_Key_Numpad_5[0] && GetAsyncKeyState(VK_NUMPAD5)) { key(Kb_Key_Numpad_5, vdb); continue; }
			if (Kb_Key_Numpad_6[0] && GetAsyncKeyState(VK_NUMPAD6)) { key(Kb_Key_Numpad_6, vdb); continue; }
			if (Kb_Key_Numpad_7[0] && GetAsyncKeyState(VK_NUMPAD7)) { key(Kb_Key_Numpad_7, vdb); continue; }
			if (Kb_Key_Numpad_8[0] && GetAsyncKeyState(VK_NUMPAD8)) { key(Kb_Key_Numpad_8, vdb); continue; }
			if (Kb_Key_Numpad_9[0] && GetAsyncKeyState(VK_NUMPAD9)) { key(Kb_Key_Numpad_9, vdb); continue; }
			if (Kb_Key_Numlock[0] && GetAsyncKeyState(VK_NUMLOCK)) { key(Kb_Key_Numlock, vdb); continue; }
			if (Kb_Key_Numpad_Divide[0] && GetAsyncKeyState(VK_DIVIDE)) { key(Kb_Key_Numpad_Divide, vdb); continue; }
			if (Kb_Key_Numpad_Multiply[0] && GetAsyncKeyState(VK_MULTIPLY)) { key(Kb_Key_Numpad_Multiply, vdb); continue; }
			if (Kb_Key_Numpad_Minus[0] && GetAsyncKeyState(VK_SUBTRACT)) { key(Kb_Key_Numpad_Minus, vdb); continue; }
			if (Kb_Key_Numpad_Add[0] && GetAsyncKeyState(VK_ADD)) { key(Kb_Key_Numpad_Add, vdb); continue; }
			if (Kb_Key_Numpad_Period[0] && GetAsyncKeyState(VK_DECIMAL)) { key(Kb_Key_Numpad_Period, vdb); continue; }
			if (Kb_Key_Numpad_Enter[0] && GetAsyncKeyState(VK_RETURN)) { key(Kb_Key_Numpad_Enter, vdb); continue; }
		}
		if (GetAsyncKeyState(VK_LMENU)) {
			if (Kb_Key_Left_Alt[0]) key(Kb_Key_Left_Alt, vdb);
			else {
				while (GetAsyncKeyState(VK_LMENU) != 0)	sleep(frequency / 4);
				clear_all_keys();
			}
			continue;
		}
		if (GetAsyncKeyState(VK_RMENU)) {
			if (Kb_Key_Right_Alt[0]) key(Kb_Key_Right_Alt, vdb);
			else {
				while (GetAsyncKeyState(VK_RMENU) != 0)	sleep(frequency / 4);
				clear_all_keys();
			}
			continue;
		}
		if (GetAsyncKeyState(VK_LWIN) || GetAsyncKeyState(VK_RWIN)) {
			while (GetAsyncKeyState(VK_LWIN) != 0 || GetAsyncKeyState(VK_RWIN) != 0) sleep(frequency / 4);
			clear_all_keys();
			continue;
		}
#pragma endregion

		if (mvdb) { //vdb size has changed. mvdb.
			vdb = vstrand;
		
			if (mvdb == 1) {
				strand = L"<anu>";
				scan_db(vdb);
				repeats = repeats[0] ? L"<anu:>" + repeats.substr(5) : L"";
				strand.clear();
			}
			
			mvdb = 0;
		}

	}



	return 0;

}