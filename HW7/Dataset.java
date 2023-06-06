
import java.util.ArrayList;
import java.util.List;

public class Dataset
{
    private List<Player> players;
    private List<Viewer> viewers;
    private List<MediaObject> objects;

    /* Dataset Constructor */
    public Dataset()
    {
        players = new ArrayList<>();
        viewers = new ArrayList<>();
        objects = new ArrayList<>();
    }

    /* Function to register observer to the Dataset */
    public void register(Player player)
    {
        players.add(player);
    }

    public void register(Viewer viewer)
    {
        viewers.add(viewer);
    }

    /* Function to remove observers from the Dataset */
    public void remove_observer(Player player)
    {
        players.remove(player);
    }

    public void remove_observer(Viewer viewer)
    {
        viewers.remove(viewer);
    }

    /* Function to add a media object to Dataset */
    public void add(Audio a)
    {
        objects.add(a);
        for (var vr : players)
            vr.add_playlist(a);
    }

    public void add(Image i)
    {
        objects.add(i);
        for (var vr : viewers)
            vr.add_viewlist(i);
    }

    public void add(Text t)
    {
        objects.add(t);
        for (var vr : viewers)
            vr.add_viewlist(t);
    }

    public void add(Video v)
    {
        objects.add(v);
        for (var vr : players)
            vr.add_playlist(v);
    }

    public void remove(Audio a)
    {
        objects.remove(a);
        for (var vr : players)
            vr.remove_playlist(a);
    }

    public void remove(Image i)
    {
        objects.remove(i);
        for (var vr : viewers)
            vr.remove_viewlist(i);
    }

    public void remove(Text t)
    {
        objects.remove(t);
        for (var vr : viewers)
            vr.remove_viewlist(t);
    }

    /* Function to remove a media object from the Dataset */
    public void remove(Video v)
    {
        objects.remove(v);
        for (var vr : players)
            vr.remove_playlist(v);
    }

    public void remove(Playable p)
    {
        objects.remove((MediaObject)p);
        for (var vr : players)
            vr.remove_playlist(p);
    }

    public void remove(Non_playable np)
    {
        objects.remove((MediaObject)np);
        for (var vr : viewers)
            vr.remove_viewlist(np);
    }
}