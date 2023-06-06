
import java.util.ArrayList;
import java.util.List;

public class Player
{
    private Playable playing_media;
    private List<Playable> playlist;

    /* Player Constructor */
    public Player()
    {
        playlist = new ArrayList<>();
    }

    /* Function to get currently playing media object */
    public Playable currently_playing()
    {
        return (playing_media);
    }

    /* Function to set currently playing media object */
    public void set_currently_playing(Playable media)
    {
        playing_media = media;
    }

    /* Function to get playlist */
    public List<Playable> get_playlist()
    {
        return (playlist);
    }

    /* Function to add a media object to the playlist */
    public void add_playlist(Playable object)
    {
        playlist.add(object);
        if (playlist.size() == 1) // First object is being set as playing media
            set_currently_playing(object);
    }

    /* Function to remove a media object from the playlist */
    public void remove_playlist(Playable object)
    {
        try
        {
            if (playlist.contains(object) == false)
                throw new ObjectNotFoundException("Object not found in the playlist");
            else
            {
                if (playing_media == object)
                {
                    int i;
                    i = playlist.indexOf(object);
                    if (i != playlist.size() - 1) // Next object of the removed object is being set as playing media
                    set_currently_playing(playlist.get(i + 1));
                    else // If removed object is the last object, previous object is being set as playing media
                        set_currently_playing(playlist.get(i - 1));
                }
                playlist.remove(object);
            }
        }
        catch (ObjectNotFoundException exc)
        {
            System.out.println(exc.getMessage());
        }
    }

    /* Function to print infos of playing media */
    public void info()
    {
        playing_media.info();
    }

    /* Function to print the names of media objects in the list */
    public void show_list()
    {
        try
        {
            if (playlist.isEmpty() == true)
                throw new ListIsEmptyException("Playlist is empty");
            else
            {
                System.out.printf("Playlist\n");
                for (int i = 0; i < playlist.size(); i++)
                    System.out.printf("%d. %s\n", i + 1, playlist.get(i).get_name());
            }
        }
        catch(ListIsEmptyException exc)
        {
            System.out.println(exc.getMessage());
        }
    }

    /* Function to set the next media object of playing media as currently playing media*/
    public void next(String type)
    {
        try
        {
            if (playlist.isEmpty() == true)
                throw new ListIsEmptyException("Playlist is empty");
            else
            {
                if (type == "audio")
                {
                    int i = playlist.indexOf(playing_media) + 1;
                    while (playlist.get(i).getClass().getSimpleName() != "Audio")
                        i++;
                    if (playlist.get(i).getClass().getSimpleName() == "Audio")
                        set_currently_playing(playlist.get(i));
                }
                else if (type == "video")
                {
                    int i = playlist.indexOf(playing_media) + 1;
                    while (playlist.get(i).getClass().getSimpleName() != "Video")
                        i++;
                    if (playlist.get(i).getClass().getSimpleName() == "Video")
                    set_currently_playing(playlist.get(i)); 
                }            
            }
        }
        catch (ListIsEmptyException exc)
        {
            System.out.println(exc.getMessage());
        }
    }

    /* Function to set the previous media object of playing media as currently playing media */
    public void previous(String type)
    {
        try
        {
            if (playlist.isEmpty() == true)
                throw new ListIsEmptyException("Playlist is empty");
            else
            {
                if (type == "audio")
                {
                    int i = playlist.indexOf(playing_media) - 1;
                    while (playlist.get(i).getClass().getSimpleName() != "Audio")
                        i--;
                    if (playlist.get(i).getClass().getSimpleName() == "Audio")
                        set_currently_playing(playlist.get(i));
                }
                else if (type == "video")
                {
                    int i = playlist.indexOf(playing_media) - 1;
                    while (playlist.get(i).getClass().getSimpleName() != "Video")
                        i--;
                    if (playlist.get(i).getClass().getSimpleName() == "Video")
                        set_currently_playing(playlist.get(i)); 
                }
            }
        }
        catch (ListIsEmptyException exc)
        {
            System.out.println(exc.getMessage());
        }
    }
}