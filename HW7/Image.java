
public class Image extends MediaObject implements Visual, Non_playable
{
    private String image_name;
    private String dimension_info;
    private String other_info;

    public Image(String in, String d, String o)
    {
        image_name = in;
        dimension_info = d;
        other_info = o;
    }

    public String get_name()
    {
        return (image_name);
    }

    public String get_dimension()
    {
        return (dimension_info);
    }

    public String get_other()
    {
        return (other_info);
    }

    public void info()
    {
        System.out.printf("Audio Name: %s\n", image_name);
        System.out.printf("Duration: %s\n", dimension_info);
        System.out.printf("Other Info: %s\n", other_info);
    }
}