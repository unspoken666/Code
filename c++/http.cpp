#include<queue>
#include<string>
#include<unordered_map>
using std::string;
using std::unordered_map;
using std::queue;
typedef bool(*Handler)(int);
class HttpTask
{
	//http请求处理的任务
	//包含socket与任务处理函数
private:
	int _cli_sock;
	Handler TaskHandler;
public:
	void SetHttpTask(int sock, Handler handle)
	{
		_cli_sock = sock;
		TaskHandler = handle;
	}
	void Handler()
	{
		TaskHandler(_cli_sock);
	}
};
class ThreadPool
{	
	//创建一定数量的线程
	//一个线程安全的任务队列
	//提供出入队列，线程池初始化，销毁的接口
private:
	int _max_thr;//最大线程数
	int _cur_thr;//当前线程数
	std::queue<HttpTask> _task_queue;
	pthread_mutex_t _mutex;
	pthread_cond_t _cond;
	static void* thr_start(void* arg);//完成线程获取任务，并完成任务
public:
	ThreadPool(int max) :_max_thr(max) {}
	bool Init();
	bool PushTask(HttpTask& tt);
	bool PopTask(HttpTask& tt);//出入队都为线程安全
	bool Destroy();
};
class HttpServer
{
	//建立服务端，接收新连接
	//为新连接创建线程池任务，添加到线程池
private:
	int _serv_sock;
	ThreadPool* _tp;


	static bool (HttpHandler)(int sock);//http任务的处理函数
public:
	bool Init();//完成服务端的建立，线程池的初始化
	bool Start();//开始获取客户端连接，创建新任务，线程池任务入队

};
class RequestInfo
{
	//包含已经解析的请求信息
public:
	std::string _method;//请求方法
	std::string _version;//版本信息
	std::string _path_info;//资源路径
	std::string _path_phys;//请求资源的实际路径
	std::string _query_string;//查询字符串
	std::unordered_map<std::string, std::string> _hdr_list;//头部信息键值对
	struct stat _st;
};
class HttpRequest
{
	//http数据的接收与解析
	//对未提供获取处理结果的接口
private:
	int _cli_sock;
	std::string _http_header;
	RequestInfo _req_info;

public:
	HttpRequest() :_cli_sock(-1) {}
	bool RecvHttpHeader();//接收http请求头
	bool ParseHttpHeader();//解析请求头
	RequestInfo&  GetReqInfo();//提供解析结果
};
class HttpResponse
{
	//提供各类请求的相应接口
	//文件请求（下载，列表）接口
	//CGI请求接口
private:
	int _cli_sock;
	std::string _etag;
	std::string _mtime;//最后一次修改时间
	std::string _cont_len;
public:
	bool Init(RequestInfo req_info);//初始化请求的响应信息
	bool ProcessFile(std::string &file);//下载
	bool ProcessList(std::string &path);//文件列表
	bool ProcessCGI(std::string & file);//处理CGI请求
};
class Upload
{
	//CGI外部程序中的文件上传功能处理接口
};
class Utils
{
	//提供各类工具接口
};