

public class Text extends MediaObject implements Non_visual, Non_playable
{
    private String text_name;
    private String other_info;

    public Text(String tn, String o)
    {
        text_name = tn;
        other_info = o;
    }

    public String get_name()
    {
        return (text_name);
    }

    public String get_other()
    {
        return (other_info);
    }

    public void info()
    {
        System.out.printf("Audio Name: %s\n", text_name);
        System.out.printf("Other Info: %s\n", other_info);
    }
}