#ifndef OPEN_DIALOG_H
#define OPEN_DIALOG_H

#include "imgui.h"
#include <functional>
#include <vector>
#include <algorithm>

#include "tinydir.h"

using namespace std;
typedef std::function<void(std::string&)> OD_CALLBACK;
class OpenDialog{
public:

	static void ShowOpen(std::vector<string> filter, OD_CALLBACK cb);
	static void ShowSave(std::vector<string> filter, OD_CALLBACK cb);
	static void SetFolderTarget(bool);

	static void loop();
private:
	static void confirmed(string &path);
	static void canceled();

	static bool isFolder(string&);

private:
	enum DialogType {
		NONE,
		OPEN,
		SAVE,
	};
	static bool is_visible;
	static bool is_folder;
	static DialogType show_type;

	static string title;

	static string file_selected;

	static OD_CALLBACK m_callback;


	static struct Path {
		vector<string> root_path;
		vector<string> files;
		vector<string> paths;
		string full_path;

		void init() {
			root_path.clear();
			
#ifdef WIN32
			tinydir_dir dir;
			char tmp[10] = "";
			for (char c = 'C'; c < 'Z'; c++)
			{
				sprintf(tmp, "%c:", c);
				tinydir_open(&dir, tmp);
				if (dir.path[0] == 0)
				{
					tinydir_close(&dir);
					break;
				}
				string tp = dir.path;
				tp.append("/");
				root_path.push_back(tp);
				tinydir_close(&dir);
			}
#else
			root_path.push_back("/");
#endif

			if (root_path.size() > 0) {
				changeRoot(0); // root as default
				update();
			}
		}

		void update() {
			full_path = "";
			for (auto it = paths.begin(); it != paths.end(); ++it)
			{
				full_path += *it;
			}

			files.clear();
			tinydir_dir dir;
			tinydir_open(&dir, full_path.c_str());
			files.push_back("..");
			while (dir.has_next)
			{
				tinydir_file file;
				tinydir_readfile(&dir, &file);
				if (file.is_dir)
				{
					string tp = file.name;
					if (tp != "." && tp != "..")
					{
						tp += "/";
						files.push_back(tp);
					}
				}
				else
				{
					files.push_back(file.name);
				}
				tinydir_next(&dir);
			}
			tinydir_close(&dir);
			std::sort(files.begin(), files.end(),[](string& a,string& b)->bool {
				bool ba = a == "..";
				bool bb = b == "..";
				bool pa = isFolder(a);
				bool pb = isFolder(b);
				if (ba) return true;
				if (bb) return false;
				if (pa != pb)
				{
					if (pa) return true;
					if (pb) return false;
				}
				return a < b;
			});
		}

		bool enter(string &folder)
		{
			if (!isFolder(folder)) return false;
			paths.push_back(folder);
			update();
			return true;
		}

		void back()
		{
			if (paths.size() > 1)
			{
				paths.pop_back();
				update();
			}
		}

		void changeRoot(int id)
		{
			if (id >= 0 && id < root_path.size())
			{
				paths.clear();
				paths.push_back(root_path[id]);
				update();
			}
		}

		// TODO
		void setFullpath(string &path) {
			// ½âÎöfullpath
		}

		string& getFullpath() { return full_path; }
		vector<string>& getRoot() { return root_path; }
		vector<string>& getFiles() { return files; }
	}m_path;

};

#endif