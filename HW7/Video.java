
public class Video extends MediaObject implements Visual, Playable
{
    private String video_name;
    private String duration_info;
    private String other_info;

    public Video(String vn, String d, String o)
    {
        video_name = vn;
        duration_info = d;
        other_info = o;
    }

    public String get_name()
    {
        return (video_name);
    }

    public String get_duration()
    {
        return (duration_info);
    }

    public String get_other()
    {
        return (other_info);
    }

    public void info()
    {
        System.out.printf("Audio Name: %s\n", video_name);
        System.out.printf("Duration: %s\n", duration_info);
        System.out.printf("Other Info: %s\n", other_info);
    }
}