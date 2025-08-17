# Philosophers (Filozofların Akşam Yemeği Problemi)

### Projenin isterleri

- Yuvarlak bir masanın etrafında filozoflar oturmuş ve aralarında birer çatal var. Önlerindeki spagettiyi yiyebilmek için filozoflar iki çatalı aynı anda kullanmak zorundalar 
<div align="center"><img src="https://github.com/mtalhaaygen/Philosophers/assets/63591196/6ca08f30-5f6f-4acb-92d2-a76c8170cef3" alt="An_illustration_of_the_dining_philosophers_problem" height="700"/></div>

burda filozoflar threadleri temsil ediyor, çatallar ise kaynakları
-  eat - think - sleep sadece bu üç etkinliği gerçekleştirebiliyorlar ve iki etkinlik aynanda yapılamaz ve mutlaka birini yapıyor olmalı
-  Filozof sayısı kadar çatal var ve spagetti iki çatalla birlikte yenilmelidir
- Filozof yemeğini bitirince çatalını tekrar masaya koyar ve uyumaya başlar. Uyandıktan sonra tekrar düşünmeye başlarlar. Yemek yedikten sonra uyumak ve uyandıktan sonra düşünmek zorunda
- filozof açlıktan öldüğünde simülasyon durur.
- her bir filozof bir thread dır.
- Her filozof çifti arasında bir çatal vardır. Bu nedenle, birden fazla filozof varsa, her filozofun sol tarafında bir çatal ve sağ tarafında bir çatal vardır. Sadece bir filozof varsa, masada sadece bir çatal olmalıdır.
- Filozofların çatalları çoğaltmasını önlemek için çatal durumunu her biri için bir mutex ile korumalısınız.
- data races olmamalıdır.
- Bir filozofun öldüğünü bildiren bir mesaj, filozofun gerçek ölümünden en fazla 10 ms sonra gösterilmelidir.

- program çalışırken alacağı argümanlar şu şekilde olacak;

`number_of_philosophers - argv[1]` filozof sayısı ve fork sayısı
`time_to_die - argv[2]` (milisaniye) açlığa dayanma süresi, bu süre boyunca aç kalan filozof ölür
`time_to_eat - argv[3]` (milisaniye) yemek yeme süresi, bu süre boyunca filozoflar iki çatal tutacak
`time_to_sleep - argv[4]` (milisaniye) uyku süresi
`number_of_times_each_philosopher_must_eat - argv[5]` (opsiyonel) filozofun kaç kere yemek yiyeceği, belirtilmemişse filzoflar ölene kadar program devam eder.

- her filozofun bir sayısı olmalı 1'den number_of_philosophers e kadar. 
- filozoflar masaya numaralarına göre sırasıyla oturur

- programın çıktıları şu şekilde olacak;
```
 durum değişiklikleri aşağıdaki gibi çıktı verilecek
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```
burada X filozof sayısı, timestamp_in_ms etkinliği 
gerçekleştirdiği süre

./philo philo_num die eat sleep yemesayisi
./philo 5 200 50 50

### Kavramlar

her proses birkaç kısımdan oluşur, threadler görselde görüldüğü gibi code data files kısımlarını paylaşır
- text: This is where the code of the process reside. This is a read-only section.
- data: This is where global and static initialized variables are stored.
- rodata: This is where constant variables are stored.
- bss: This is where global and static un-initialized variables are stored.
- stack: This is where the local variables and function calls are stored.
- heap: This is where user allocated memory is stored. When the user uses malloc,
calloc, new etc.
<div align="center">
  <img src="https://github.com/mtalhaaygen/Philosophers/assets/63591196/2d1faab6-69bb-4596-a5ee-622b7f828d50" alt="4_01_ThreadDiagram">
</div>
There are several ways to access a thread in a multithreaded program, including:
1. Joining a thread: You can wait for a thread to finish by calling pthread_join , which
blocks the calling thread until the specified thread terminates.
8 - philosophers 7
2. Detaching a thread: You can detach a thread using pthread_detach , which means
that its resources will be automatically freed when it terminates, and it cannot be
joined.
3. Terminating a thread: You can terminate a thread by calling pthread_exit , which
allows the thread to exit and return a value to the caller.
4. Cancelling a thread: You can cancel a thread by calling pthread_cancel , which
terminates the thread immediately.
5. Setting thread attributes: You can set various attributes of a thread, such as its
stack size or scheduling policy, by using pthread_attr_init ,
pthread_attr_setstacksize , and other related functions.
6. Synchronizing threads: You can synchronize the execution of threads using
synchronization mechanisms such as mutexes, semaphores, or condition
variables.
7. Sending signals to a thread: You can send signals to a thread using the
pthread_kill function, which can be used to send any signal to a specified thread.
These are some of the most common ways to access a thread in a multithreaded
program, but the exact methods available may depend on the implementation of the
POSIX threads library.

Data races : Bir thread bir değişkene yada değiştirilebilir bir nesneye erişirken aynı anda başka bir thread ona yazmaya çalışır. Bu durumda kod beklenmeyen çıktılar verebilir. Data Race diyebilmek için erişimlerden en az birinin yazma amaçlı olması gerekir.
Data races den kaçınmak için mutexler, semaforlar, spinlocklar, ??... kullanılabilir
- Race Condition kavramı Data Race kavramından farklıdır
![g](https://i.stack.imgur.com/FDc5b.png)

Race Condition : Olayların zamanlaması veya sırası bir kod parçasının doğruluğunu etkilediğinde Race Condition durumu oluşur.

Bir değişkenin değerini arttırmak üç adımdan oluşuyor.
1 - değişkenin değeri cpu daki bir register a yüklenir
2 - register'ın değeri 1 arttırılır
3 - bu değer registerdan değişkene atılır

 aynı veri üzerinde işlem yapan iki farklı thread düşünelim, ikiside int olan bu değişkeni arttırıyor olsun. Her bir thread veriyi okur, arttırır, belleğe yazar. İşte böyle bir durumda threadler veriyi aynanda okursa arttırma işlemini ikiside yapar, ve değer bir kere arttırılmış olur. Eğer senkron bir şekilde arttırsalardı iki kere arttırılmış olacaktı
Race Condition durumu yalnızca multi core işlemcilerde meydana gelir. Single core bir işlemcide bu durumla karşılaşmanız çok olası değildir. Lakin günümüz işlemcilerinin çoğu multicore :D

- Mutexler ile data races i önleyeceğiz. Senkron bir şekilde paylaşılan veriye erişeceğiz. Bir başka deyişle çatallar senkron bir şekilde kullanılacak
// Mutex : Mutex’ler uygulamanın yazıldığı dil ve Runtime tarafından sağlanan basit veri yapılarıdır. Farklı Thread’ler tarafından paylaşılan her bir kaynak için kaynağa olan erişimi düzenlemek üzere bir Mutex yaratılır. Paylaşılan kaynağa erişim yapılan kod bölgesi `Critical Section` olarak adlandırılır. Kaynakla işi olan Thread, Mutex'in sahipliğini almaya (Acquire) çalışır. Mutex o anda başka bir Thread tarafından tutulmuyorsa Thread Mutex'i alır, Critical Section'a girerek ilgili kaynağı kullanır. Diğer durumda, yani Mutex o anda başka bir Thread tarafından kullanılıyor ise, ikinci Thread işlemci tarafından beklemeye alınır. Mutex'i tutan Thread Critical Section'ı bitirip Mutex'i bırakırken, halihazırda Mutex'in bırakılmasını bekleyen Thread uyandırılır ve Mutex'in sahipliğini alarak Critical Section'a girer ve paylaşılan kaynağa erişim sağlar.

- Deadlock : iki yada daha fazla işlemin (process - thread) devam etmek için birbirlerini beklemesi ve sonuçta devam edememesidir. Örnek olarak her filozofun bir çatalı eline alması ve hiçbirinin yiyememesi durumudur.
Oluşması için Coffman şartları gereklidir (mutual exclusion, hold and wait, no preemption, circular wait)
<div align="center">
  <img src="https://github.com/mtalhaaygen/Philosophers/assets/63591196/e1f0a379-5293-4a5a-ae92-fa5186f2b474" alt="deadlock">
</div>


[incelemek isteyebilirsin](https://www.geeksforgeeks.org/introduction-of-deadlock-in-operating-system/)

### Threads vs Processes
ikisi birbirine benziyor ama karıştırmayalım. Bir process birden falza thread içerebilir. Sistem kaynakları processdeki tüm threadlar arasında paylaşılır. Yanii threads oluşturulduğunda processdeki datalar ne ise tüm threadler bunları kullanır ama fork yaptığımızda oluşan iki farklı process için tüm datalar dublicate edilir. Her bir process için her bir data farklı adreste tutulur.

Biz bir thread oluşturduğumuzda main threadin yanında bir thread daha oluşmuş olur, toplamda iki threadimiz olmuş olur iki thread oluşturursak toplam 3 threadimiz olur
`eğer main thread sonlanırsa diğer tüm threadler de sonlanır` 
threadler sadece prosesler altında var olabilirler. proseslerin aksine threadler birbirleriyle ilintili çalışırlar ve aynı bellek kaynağını
paylaşırlar.

ekstra bilgi Amdahl Law
Bu yasa ile multiprocessor ortamlarda bir işin ne kadarını paralelleştirirseniz, işin ne kadar hızlanacağını hesaplayabilirsiniz. İşlemci sayısı bir noktadan sonra ne kadar artarsa artsın speedup neredeyse değişmiyor
![400px-AmdahlsLaw svg](https://github.com/mtalhaaygen/Philosophers/assets/63591196/4286e7b0-6967-4c11-a8dd-470ad84b81cb)

// -Wall bir dizi warning etkinleştirilir, ama tümü değil
// -Wextra ekstra warningler etkinleştirilir
// -Werror warningleri error a dönüştürür
// -w tüm warningleri engeller
// -g hata ayıklama bilgileri üretir. ??

### Kullanılacak fonksiyonlar

//pthread_t abstract type is implemented as an integer (long unsigned nt) (4 byte or 8 byte) thread ID


Bir thread pthread_create() işlevinin başarılı dönüşü ile başlar
pthread_join() ile thread çalışmayı bitirir, ikinci parametreye verdiğimiz değişkene
threadin fonksiyonunun return ettiği void* tipindeki değer atanır. Örneğin
```C
void *worker_thread(void *arg)
{
    int *my_data = (int*)arg; /* data received by thread */
    printf("This is worker_thread\n");
    return (arg);
}

int main()
{
    pthread_t th; // thread id
    pthread_attr_t attr; // thread in attribute larının olduğu değişken
    int* rv; // return value
    int t[1] = {11};  // data passed to the new thread
    pthread_attr_init(&attr); // attributler initialize ediliyor
    pthread_create(&th, &attr, &worker_thread, (void*)t);
    pthread_join(th, (void **)&rv);
    return (0);
}
```

bir döngü ile birsürü thread oluşturursak
pthread_create() pthread_join() fonksiyonlarını aynı döngünün içinde kullandığımızda mutex ile bu durumu kontrol altına aldığımızda dadad da dahada da biri başlar biri biter sıra ile çalışır biterler
ancak biz kaynaklar çakışmıyor ise aynı anda çalışan threadler istiyoruz

// pthread_detach();
// pthreaad_mutex_t my_mutex; mutexi tanımlıyoruz
// pthread_mutex_init(&my_mutex, NULL); başlatıyoruz
// pthread_mutex_lock(); artık kilitleyebiliriz
// pthread_mutex_unlock(); kilidi açıp 
// pthread_mutex_destroy(&my_mutex); mutexi kaldırıyoruz ayrılan belleği kaldırmak içn 


<!--

### Algoritma
#### Garson çözümü

Garson, sürekli olarak masada boş duran ve filozoflar tarafından yemek için kullanılan çatalların sayılarını takip etmektedir. Bir şekilde her filozof, masadan çatal alabilmek için garsonun iznini istemek zorundadır. Şayet garson izin vermezse filozof masadan çatal alamaz. Bu çözümde filozofların kıtlık problemi (starvation) ile karşılaşmaları engellenir çünkü mantıklı bir garson tasarımı, bütün filozoflara yemek imkanı tanır. Aynı zamanda ölümcül kilitlenme (deadlock) ihtimali de çözülmüştür çünkü garson hiçbir filozofu sonsuza kadar bekletmez. Yani filozofların birbirini bekleyerek sonsuza kadar yaşlanması sorunu çözülmüştür.

Çözümün daha iyi anlaşılabilmesi için, garsonun, saat yönünde masada döndüğünü, düşünelim. O anda işaretlediği filozof yemek yiyor, sonraki yemiyor sonraki yiyor ve böylece kaç filozof farsa, sırayla bir yiyor bir yemiyor şeklinde düşünülebilir. Bu durumda her filozofun yemek yemek için yeterli çatalı (veya sopası) bulunuyor demektir. Sonra garson, sırasıyla bir yönde (örneğin saat yönünde) dönerek masayı dolaşmakta ve sıradaki filozofa yemek yedirmekte (ve dolayısıyla sıradaki filozoftan sonraki yememekte ve sonraki yemekte ve böylece bütün masadakiler bir yer bir yemez şeklinde işaretlenmektedir).
int wait_index = 1;

wihle  wait_index++;

örrneğin 7 filozof olsun, filozof sayısı tek sayı olduğundan tekler yesin çiftler yesin yapamayız. Sıra ile her filozof bir tur bekleyecek, bekleyen filozoftan sonrası için sırayla birer atlayarak filozoflara yeme komutu verebiliriz

yeme komutu filozofun rFork ve lFork u mutex_lock yapması anlamına geliyor, yeme süresi bitince unlock yapılacak diğer tura geçilecek




***
##### ***TAMAMLANANLAR***
1- argüman sayısı kontrolü 
2- argüman check
3- struct yapılarını oluştur
    - t_philo
    - ti_data
4- ti_data yı doldur.
        all_death = 0; 1 olduğunda tüm philolar freelenecek ve program sonlandırılacak
5- philo number sayısı kadar 
        t_philo oluştur
            philo_id 1 den başlayacak (0 yok)
            tüm threadler aynı fonksiyonu çalıştıracak lakin philo_id ye göre işlem yapacak
        pthread_mutex_t *forks değişkeni ile her fork için mutex oluşturuyoruz 
            ve bu mutexlerin adreslerini philoların rFork ve lFork mutexlerine atansın (birinin leftFork u diğerinin rightFork u olacak)
6- gettimeofday ile milisaniye cinsinden Unix timestamp tan itibaren geçen toplam süreyi hesaplayan get_time fonksiyonu yaz. İlk anda bu süreyi al sonrasında başlangıçtan itibaren ne kadar zaman geçtiğini ilk aldığın değerden çıkartarak bulacaksın

7- oluşturulan threadlerin yani phliloların hepsi aynı fonksiyonu çalıştıracak dedik, bu fonksiyon philoyu parametre olarak alacak
çift sayıda philo varsa çiftler yesin diğerleri bir kaç milisaniye bekleyip döngüye girecek
döngü nasıl olacak
```C
while (1)
{
    eating() // sleepingi bu fonksiyonun sonunda çağıracağız ikisi ardı ardına çalışacak zaten
    thinking(); // eğer filo sayısı tek ise sırayla biri thinking yapacak 
    // thinking için belirli bir süre yok, bir yeme süresi kadar beklese yeterli
}
```
***
7 - Tüm ölüm durumları
*eğer filozof aç kalırsa (last_eat i almalısın çünkü time_to_die ı geçerse simülasyonu durduracağız)
*eğer tüm filoların yeme sayısı max a ulaştıysa (ayrıca yeme sayısı number_of_times_each_philosopher_must_eat'e ulaştıysa daha yememeli)
pthread_create döngüsünün nün ardından
	while (data->death != 1)
		ft_check_death(philo);
        ile ölümü kontrol et
bu döngüden çıkınca aşağıdaki kod ile herşeyi sonlandırıyoruz
```C
void	exit_threads(t_env *env)
{
	int	i;

	if (env->count == 1)
		pthread_detach(env->philos[0].thread_id); // detach ne işe yarıyor, mutlaka sadece bir filozof var ise nasıl bir çıktı vermeli? kontrol et
	else
	{
		i = -1;
		while (++i < env->count)
			pthread_join(env->philos[i].thread_id, NULL);
	}
	i = -1;
	while (++i < env->count)
		pthread_mutex_destroy(&env->forks[i]);
	pthread_mutex_destroy(&env->meal);
	pthread_mutex_destroy(&env->writing);
	i = -1;
	while (++i < env->count)
		free(env->philos[i].pos_str);
	free(env->philos);
	free(env->forks);
}
```



10 - durumu yazdırmak için aşağıdaki gibi bir fonk. yaz
    print_status(philo, "is thinking")
    print_status(philo, "is sleeping")
    print_status(philo, "is eating")
    print_status(philo, "has taken a fork")

https://www.mustafayemural.com/cpp-my000047/
->
