package theji.algorithmproject.repository;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.Test;
import theji.algorithmproject.Member.Member;

import java.util.List;

import static org.assertj.core.api.AssertionsForClassTypes.assertThat;

class MemoryMemberRepositoryTest {

    MemoryMemberRepository repository = new MemoryMemberRepository();


    /*
    @AfterEach : 한번에 여러 테스트를 실행하면 메모리 DB에 직전 테스트의 결과가 남을 수 있다.
    이렇게 되 면 다음 이전 테스트 때문에 다음 테스트가 실패할 가능성이 있다.
    @AfterEach 를 사용하면 각 테스트가 종 료될 때 마다 이 기능을 실행한다. 여기서는 메모리 DB에 저장된 데이터를 삭제한다.
     */
    @AfterEach
    public void afterEach() {
        repository.clearStore();
    }

    @Test
    void save() {
        //givn
        Member member = new Member();
        member.setName("1theJi");
        //when
        repository.save(member);
        //then
        Member result = repository.findById(member.getId()).get();
        assertThat(member).isEqualTo(result);
    }

    @Test
    void findById() {
        //givn
        Member member = new Member();
        member.setName("1theJi");
        //when
        repository.save(member);
        //then
        Member result = repository.findById(member.getId()).get();
        assertThat(member).isEqualTo(result);
    }

    @Test
    void findByName() {
        //given
        Member member1 = new Member();
        member1.setName("1theJi01");
        repository.save(member1);

        Member member2 = new Member();
        member2.setName("1theJi02");
        repository.save(member2);

        //when
        Member result = repository.findByName("1theJi01").get();

        //then
        assertThat(result).isEqualTo(member1);

    }

    @Test
    void findAll() {
        //given
        Member member1 = new Member();
        member1.setName("1theJi01");
        repository.save(member1);

        Member member2 = new Member();
        member2.setName("1theJi02");
        repository.save(member2);

        //when
        List<Member> resultList = repository.findAll();

        //then
        assertThat(resultList.size()).isEqualTo(2);
    }
}