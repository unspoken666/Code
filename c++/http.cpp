#include<queue>
#include<string>
#include<unordered_map>
using std::string;
using std::unordered_map;
using std::queue;
typedef bool(*Handler)(int);
class HttpTask
{
	//http�����������
	//����socket����������
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
	//����һ���������߳�
	//һ���̰߳�ȫ���������
	//�ṩ������У��̳߳س�ʼ�������ٵĽӿ�
private:
	int _max_thr;//����߳���
	int _cur_thr;//��ǰ�߳���
	std::queue<HttpTask> _task_queue;
	pthread_mutex_t _mutex;
	pthread_cond_t _cond;
	static void* thr_start(void* arg);//����̻߳�ȡ���񣬲��������
public:
	ThreadPool(int max) :_max_thr(max) {}
	bool Init();
	bool PushTask(HttpTask& tt);
	bool PopTask(HttpTask& tt);//����Ӷ�Ϊ�̰߳�ȫ
	bool Destroy();
};
class HttpServer
{
	//��������ˣ�����������
	//Ϊ�����Ӵ����̳߳�������ӵ��̳߳�
private:
	int _serv_sock;
	ThreadPool* _tp;


	static bool (HttpHandler)(int sock);//http����Ĵ�����
public:
	bool Init();//��ɷ���˵Ľ������̳߳صĳ�ʼ��
	bool Start();//��ʼ��ȡ�ͻ������ӣ������������̳߳��������

};
class RequestInfo
{
	//�����Ѿ�������������Ϣ
public:
	std::string _method;//���󷽷�
	std::string _version;//�汾��Ϣ
	std::string _path_info;//��Դ·��
	std::string _path_phys;//������Դ��ʵ��·��
	std::string _query_string;//��ѯ�ַ���
	std::unordered_map<std::string, std::string> _hdr_list;//ͷ����Ϣ��ֵ��
	struct stat _st;
};
class HttpRequest
{
	//http���ݵĽ��������
	//��δ�ṩ��ȡ�������Ľӿ�
private:
	int _cli_sock;
	std::string _http_header;
	RequestInfo _req_info;

public:
	HttpRequest() :_cli_sock(-1) {}
	bool RecvHttpHeader();//����http����ͷ
	bool ParseHttpHeader();//��������ͷ
	RequestInfo&  GetReqInfo();//�ṩ�������
};
class HttpResponse
{
	//�ṩ�����������Ӧ�ӿ�
	//�ļ��������أ��б��ӿ�
	//CGI����ӿ�
private:
	int _cli_sock;
	std::string _etag;
	std::string _mtime;//���һ���޸�ʱ��
	std::string _cont_len;
public:
	bool Init(RequestInfo req_info);//��ʼ���������Ӧ��Ϣ
	bool ProcessFile(std::string &file);//����
	bool ProcessList(std::string &path);//�ļ��б�
	bool ProcessCGI(std::string & file);//����CGI����
};
class Upload
{
	//CGI�ⲿ�����е��ļ��ϴ����ܴ���ӿ�
};
class Utils
{
	//�ṩ���๤�߽ӿ�
};