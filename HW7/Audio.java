

public class Audio extends MediaObject implements Non_visual, Playable
{
    private String audio_name;
    private String duration_info;
    private String other_info;

    /* Constructor of Audio */
    public Audio(String an, String d, String o)
    {
        audio_name = an;
        duration_info = d;
        other_info = o;
    }

    /* Getter of audio_name */
    public String get_name()
    {
        return (audio_name);
    }

    /* Getter of duration_info */
    public String get_duration()
    {
        return (duration_info);
    }

    /* Getter of other_info */
    public String get_other()
    {
        return (other_info);
    }

    /* Function to print object infos */
    public void info()
    {
        System.out.printf("Audio Name: %s\n", audio_name);
        System.out.printf("Duration: %s\n", duration_info);
        System.out.printf("Other Info: %s\n", other_info);
    }
}